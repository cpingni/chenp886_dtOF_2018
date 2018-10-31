#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    // create one particle system at center screen -- see ParticleSystem.cpp + ParticleSystem.hpp
    
//    glm::vec2 pos = glm::vec2(ofGetMouseX(),ofGetMouseY());
//    ParticleSystem particleSystem = ParticleSystem(pos);
//
//    particleSystems.push_back(particleSystem);
//
    // setup general gravity force
    
    gravity = glm::vec2(0, .15);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0; i<particleSystems.size(); i++){
        particleSystems[i].applyForce(gravity);
        particleSystems[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<particleSystems.size(); i++){
        particleSystems[i].draw();

    }
    ofDrawBitmapString("Drag MOUSE to draw", 20, 20);
    ofDrawBitmapString("Click SPACE to reset", 20, 40);
}

//--------------------------------------------------------------
//void ofApp::mouseReleased(int x, int y, int button){
//
//    // create a new particle system at mouse position on click
//
//    particleSystems.push_back( ParticleSystem(glm::vec2(x,y)) );
//
//}

void ofApp::mouseDragged(int x, int y, int button){

    particleSystems.push_back( ParticleSystem(glm::vec2(x,y)));
    
}

void ofApp::keyReleased(int key){
    if(key == ' '){
        particleSystems.clear();
    }

}







