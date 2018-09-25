//
//  balls.h
//  w03_h01_balls
//
//  Created by Ping-ni Chen on 9/19/18.
//
#pragma once
#include "ofMain.h"

class Balls {
public:
    void setup(float posX, float posY, float radius);
    void update();
    void draw();
    

//    glm::vec2 getCenter();
    
    float r;

    
    glm::vec2 pos;
    glm::vec2 vel;
    
    ofColor color;

    
};


