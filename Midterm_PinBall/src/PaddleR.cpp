//
//  PaddleL.cpp
//  Midterm_PinBall
//
//  Created by Ping-ni Chen on 10/30/18.
//

#include "PaddleR.hpp"


PaddleR::PaddleR()
{
    pos = glm::vec2(0);
    angleRadians = 0;

    setup();
}

PaddleR::PaddleR(glm::vec2 _pos, float angleDegrees)
{
    pos = _pos;
    angleRadians = ofDegToRad(angleDegrees);
    
    setup();
}

/////////// make right paddle /////////

void PaddleR::setup()
{
    circlePositions.clear();
    circleRadius.clear();
    
    // construct the circles:
    
    // find the direction the paddle is pointing in:
    // angle to vector --> glm::vec2(cos(radians), sin(radians))
    glm::vec2 direction;
    direction.x = cos(angleRadians);
    direction.y = sin(angleRadians);
    
    for (int i=0; i<30; i++)
    {
        // decreasing circle size:
        float radius = ofMap(i, 0,29, 20,5);
        // increasing circle distance from paddle pos:
        float distance = ofMap(i, 0,29, 0,150);
        
        
        glm::vec2 circlePos = pos + direction * distance * -1;
        
        
        // store the circle position and radius:
        circlePositions.push_back(circlePos);
        circleRadius.push_back(radius);
    }
}

///////////// draw right paddle /////////

void PaddleR::draw()
{
    for (int i=0; i<circlePositions.size(); i++)
    {
        ofDrawCircle(circlePositions[i], circleRadius[i]);
    }
}

///////////// rotate paddle //////////////
void PaddleR::rotate(float degrees){
    angleRadians += ofDegToRad(degrees);
    setup();
}

bool PaddleR::checkCollision(glm::vec2 ballPos, float ballRadius){
    
    bool collided = false;

    for (int i=0; i<circlePositions.size(); i++)
    {
        glm::vec2 diff = circlePositions[i] - ballPos;
        float distance = glm::length(diff);
        if (distance <= circleRadius[i] + ballRadius)   
        {
            collided = true;
            break;
        }
    }
    return collided;
    
}
