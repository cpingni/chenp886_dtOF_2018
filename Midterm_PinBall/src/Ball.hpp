//
//  Ball.hpp
//  Midterm_PinBall
//
//  Created by Ping-ni Chen on 10/29/18.
//
#pragma once

#include "ofMain.h"

class Ball {
public:

    void setup(glm::vec2 _pos, float _radius);
    void update();
    void draw();
    void reset();
    
    glm::vec2 pos, speed;
    float radius;
    
    int lives = 3;
    


};
