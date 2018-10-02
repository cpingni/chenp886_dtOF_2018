//
//  pupils.h
//  w04_h01_
//
//  Created by Ping-ni Chen on 10/1/18.
//
#pragma once
#include "ofMain.h"

class Pupils{
public:
    void setup();
    void update();
    void draw();

    glm::vec2 pupilR;
    glm::vec2 pupilL;
    
    ofColor(pupilColor);
    
};
