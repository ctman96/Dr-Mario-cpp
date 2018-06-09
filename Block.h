//
// Created by Cody on 6/8/2018.
//

#ifndef DRMARIO_BLOCK_H
#define DRMARIO_BLOCK_H

enum class Color {red, blue, yellow};

class Block {
private:
    int x;
    int y;
    Color color;

public:
    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    Color getColor() const;

};


#endif //DRMARIO_BLOCK_H
