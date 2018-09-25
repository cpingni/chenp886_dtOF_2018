//
//  balls.cpp
//  w03_h01_balls
//
//  Created by Ping-ni Chen on 9/19/18.
//

#include "balls.h"

void Balls::setup(float posX, float posY, float radius){
    pos = glm::vec2(posX,posY);
    vel = glm::vec2(0,0);
    r = radius;
    
    color = ofColor(255);
    
}


void Balls::update(){
    pos += vel;
    if(pos.x > ofGetWidth()){

        pos.x = ofGetWidth();
        vel.x = vel.x * -1;
    
    }
    else if (pos.x < 0){
    
        pos.x = 0;
        vel.x = vel.x * -1;
    }
    
    if(pos.y > ofGetHeight()){

        pos.y = ofGetHeight();
        vel.y = vel.y * -1;
    }
    else if (pos.y < 0){

        pos.y = 0;
        vel.y = vel.y * -1;
    }
    
}
void Balls::draw(){
    ofSetColor(color);
    ofDrawCircle(pos.x, pos.y, ofRandom(r));
    ofSetColor(255);
    
}
