//
//  Ball.cpp
//  Midterm_PinBall
//
//  Created by Ping-ni Chen on 10/29/18.
//

#include "Ball.hpp"


void Ball::setup(glm::vec2 _pos, float _radius){
    
    pos = _pos;
    radius = _radius;
    
    pos.x = ofGetWidth()*0.5;
    pos.y = 50;
    float angle = ofRandom(TWO_PI);
    speed.x = ofRandom(7,10)* cos(angle);
    speed.y = ofRandom(7,10)* sin(angle);
    

}
void Ball::update(){

///////////// ball moves ////////////
    pos += speed;
    
///////////// ball bounce ////////////
    if(pos.x > ofGetWidth()){
        
        pos.x = ofGetWidth();
        speed.x *= -1;
        
    }
    else if (pos.x < 0){
        
        pos.x = 0;
        speed.x *= -1;
    }
    
    if(pos.y > ofGetHeight()){
        lives--;
        reset();    
    } else if (pos.y < 0){
        pos.y = 0;
        speed.y *= -1;
    }
    
//////////// when lives reach 0 ///////////
    bool gameover = false;
    if(lives == 0){
        reset();
        lives = 3;
    }
    return gameover;
}

void Ball::draw(){
    

    ofDrawCircle(pos,radius);


}

void Ball::reset(){
    
    pos.x = ofGetWidth()*0.5;
    pos.y = 50;
    float angle = ofRandom(TWO_PI);
    speed.x = ofRandom(7.,10.)* cos(angle);
    speed.y = ofRandom(7.,10.)* sin(angle);
}
