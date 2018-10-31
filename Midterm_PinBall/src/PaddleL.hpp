//
//  PaddleL.hpp
//  Midterm_PinBall
//
//  Created by Ping-ni Chen on 10/30/18.
//

#pragma once
#include "ofMain.h"

class PaddleL {
public:
    
    PaddleL();
    PaddleL(glm::vec2 _pos, float angleDegrees);
    
    void setup();
    void draw();
    void rotate(float degrees);
    bool checkCollision(glm::vec2 ballPos, float ballRadius);
    
    glm::vec2 pos;
    float angleRadians;
    
    // store each circle's postiion and radius:
    vector<glm::vec2>   circlePositions;
    vector<float>       circleRadius;
    
    
};
