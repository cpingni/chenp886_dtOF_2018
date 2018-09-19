//
//  circle.h
//  w2_hw
//
//  Created by Ping-ni Chen on 9/11/18.
//

#pragma once
#include "ofMain.h"

class Circle{
public:
    
    void setup(float posX, float posY, float radius);
    void update();
    void draw();
    void keyReleased();
    
    ofColor color;
    float x, y, r ;
    
    float dirX;
    float dirY;
    
    bool key = false;
    
};
