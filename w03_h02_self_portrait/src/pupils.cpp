//
//  pupils.cpp
//  w04_h01_
//
//  Created by Ping-ni Chen on 10/1/18.
//

#include "pupils.h"
void Pupils::setup(){
//    pupilR = glm::vec2(ofGetWidth()*0.5 -50,100);
//    pupilL = glm::vec2(ofGetWidth()*0.5 +50,100);
    pupilColor = ofColor(0);
    ofSetCircleResolution(100);
    
}
void Pupils:: update(){
    glm::vec2 mouse;
    mouse.x = ofGetMouseX();
    mouse.y = ofGetMouseY();
    
    float pct = .05;
    pupilR = pupilR * ( 1.-pct) + mouse * pct;
    
    pupilR.x= ofMap(ofGetMouseX(), 0, ofGetWidth(), ofGetWidth()*0.5-65, ofGetWidth()*0.5-35);
    pupilR.y= ofMap(ofGetMouseY(), 0, ofGetHeight(), 85, 115);
    
    pupilL.x= ofMap(ofGetMouseX(), 0, ofGetWidth(), ofGetWidth()*0.5+35, ofGetWidth()*0.5+65);
    pupilL.y= ofMap(ofGetMouseY(), 0, ofGetHeight(), 85, 115);
}
void Pupils::draw(){
    ofSetColor(pupilColor);
    ofDrawCircle(pupilR,10);
    ofDrawCircle(pupilL,10);
    ofSetColor(0);

    
}
