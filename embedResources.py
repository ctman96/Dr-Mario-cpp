# Simple build script designed to convert resources into bytearrays
# and place the arrays into a generated c header file in order to
# embed them into a project
#
# Created by Cody Newman on 6/9/2018


import os

curdir = os.path.dirname(__file__)
out = curdir+"/src/main/resources.h"
resources = curdir+"/Resources"


# Takes string file, returns a bytearray generated from the file
# file is the path of the file to be converted
def convert(file):
    with open(file, "rb") as imageFile:
        img = imageFile.read()
        ba = bytearray(img)
        return ba


# Takes a filepointer f, bytearray b, and string n
# f is the file being written to
# b is the bytearray being written
# n is the name of the file the bytearray represents
# No output
def write_array(f, b, n):
    f.write("\n")
    name = n.replace(".", "_")
    f.write("static unsigned char " + name + "[] = {\n\t")
    l = len(b)
    c = 0
    for byte in b:
        hex = '0x' + format(byte, '02x')
        # print('0x'+format(byte, '02x'))
        f.write(hex)
        if c < l:
            f.write(", ")
        c += 1

    f.write("};\n")


try:
    os.remove(out)
except OSError:
    pass

f = open(out, "w+")

f.write("//This generated code contains the byte arrays of resources\n\n")

f.write("#ifndef RESOURCES_H\n#define RESOURCES_H\n")

count = 0

# Sprites
sprites = resources+"/Sprites"
for file in os.listdir(sprites):
    if file.endswith(".png"):
        b = convert(os.path.join(sprites, file))
        write_array(f, b, file)
        count += 1

# TODO: same thing for audio and fonts, if possible

f.write("\n#endif")

print("Converted " + str(count) + " resources, and added to " + out)
