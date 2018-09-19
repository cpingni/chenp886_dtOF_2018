//
//  circle.cpp
//  w2_hw
//
//  Created by Ping-ni Chen on 9/11/18.
//

#include "circle.h"

void Circle::setup(float posX, float posY, float radius){
    
    x = posX;
    y = posY;
    r = radius;
    
    dirX = 0;
    dirY = 0;
    

}

void Circle::update(){
    
    x += dirX;
    y += dirY;
    r += ofRandom(-1,1);
    

    if(x > ofGetWidth()){
        x = ofGetWidth();
        dirX = dirX * -1;
        
    }
    else if (x < 0){
        x = 0;
        dirX = dirX * -1;
    }
    
    if(y > ofGetHeight()){

        y = ofGetHeight();
        dirY = dirY * -1;
    }
    else if (y < 0){
        y = 0;
        dirY = dirY * -1;
    }
    
}
void Circle::draw(){
    ofDrawCircle(x, y, r);
}

void Circle::keyReleased(){
    ofSetColor(color);
    color.set(ofRandom(255),ofRandom(255),ofRandom(255));
}
