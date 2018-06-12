# Simple build script designed to convert resources into bytearrays
# and place the arrays into a generated c header file in order to
# embed them into a project
#
# Created by Cody Newman on 6/9/2018


import os, json

curdir = os.path.abspath(os.path.dirname(__file__))
out = os.path.join(curdir, "src", "main", "resources.h")
resources = os.path.join(curdir, "Resources")


# Takes string file, returns a bytearray generated from the file
# file is the path of the file to be converted
def convert(file):
    print(" Converting to bytearray...")
    with open(file, "rb") as imageFile:
        img = imageFile.read()
        ba = bytearray(img)
        print(" Done")
        return ba


# Takes a filepointer f, bytearray b, and string n
# f is the file being written to
# b is the bytearray being written
# n is the name of the file the bytearray represents
# No output
def write_array(f, b, n):
    print(" Writing bytes ...")
    f.write("\n")
    name = n.replace(".", "_")
    f.write("static unsigned char " + name + "[] = {\n\t")
    l = len(b)
    c = 1
    for byte in b:
        hex = '0x' + format(byte, '02x')
        # print('0x'+format(byte, '02x'))
        f.write(hex)
        if c < l:
            f.write(", ")
        c += 1

    f.write("};\n")
    print(" Done")
    return


# Takes file path fin, filepointer fo
# f is the json atlas file being written from
# fo is the file being written to
# No output
def write_atlas(fin, fo):
    fo.write("\n")
    # Open a filepointer for the atlas
    with open(fin) as fi:
        #Load the json object into python
        sheets = json.load(fi)
        for sheet in sheets:
            # Start writting the array object
            fo.write("static const SDL_Rect "+sheet['name']+"[] {")

            # length and counter for placing commas
            l = len(sheet['sprites'])
            c = 1
            for sprite in sheet['sprites']:
                x = str(sprite["x"])
                y = str(sprite["y"])
                w = str(sprite["w"])
                h = str(sprite["h"])
                # If x,y,w,h are all there, write it to the array
                if all(v is not None for v in [x, y, w, h]):
                    fo.write("SDL_Rect{"+x+","+y+","+w+","+h)
                    fo.write("}")
                # Otherwise, write a default entry and alert the console
                else:
                    fo.write("SLD_Rect{0,0,0,0}")
                    print("Error at "+sheet+", sprite "+c)

                if c < l:
                    f.write(", ")
                c += 1

            fo.write("};\n")

    fo.write("\n")
    return


# If the output file already exists, delete it
try:
    os.remove(out)
except OSError:
    pass

# Create the output file, open it for reading+writing
f = open(out, "w+")

f.write("//This generated code contains the byte arrays of resources\n\n")

f.write("#ifndef RESOURCES_H\n#define RESOURCES_H\n\n")

f.write("#include <SDL_rect.h>\n")

# Counter for number of resources processed
count = 0

# Sprites
sprites = os.path.join(resources, "Sprites")
for file in os.listdir(sprites):
    if file.endswith(".png"):
        print("Found spritesheet: "+file)
        b = convert(os.path.join(sprites, file))
        write_array(f, b, file)
        count += 1
    if file == "atlas.json":
        print("Found sprite atlas")
        write_atlas(os.path.join(sprites, file), f)
        count += 1


# TODO: same thing for audio and fonts, if possible

f.write("\n#endif")

print("Converted " + str(count) + " resources, and added to " + out)
