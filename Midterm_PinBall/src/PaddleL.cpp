//
//  PaddleL.cpp
//  Midterm_PinBall
//
//  Created by Ping-ni Chen on 10/30/18.
//

#include "PaddleL.hpp"


PaddleL::PaddleL()
{
    pos = glm::vec2(0);
    angleRadians = 0;
    
    setup();
}

PaddleL::PaddleL(glm::vec2 _pos, float angleDegrees)
{
    pos = _pos;
    angleRadians = ofDegToRad(angleDegrees);

    setup();
}

/////////// make left paddle /////////

void PaddleL::setup()
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
        
        glm::vec2 circlePos = pos + direction * distance;
        
        
        // store the circle position and radius:
        circlePositions.push_back(circlePos);
        circleRadius.push_back(radius);
    }
}

/////////// draw left paddle /////////
void PaddleL::draw()
{
    for (int i=0; i<circlePositions.size(); i++)
    {
        ofDrawCircle(circlePositions[i], circleRadius[i]);
    }
}

/////////// rotate the paddle /////////
void PaddleL::rotate(float degrees){
    angleRadians += ofDegToRad(degrees);
    setup();
}


bool PaddleL::checkCollision(glm::vec2 ballPos, float ballRadius){
    
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

