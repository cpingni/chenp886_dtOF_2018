#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    

    for(int i=0; i<50; i++){
        float x = ofRandom(0,ofGetWidth());
        float y = ofRandom(0,ofGetHeight());
        float r = ofRandom(2,50);
        float time = ofGetElapsedTimef();
        float speed = ofMap(r, 2,50,10,1) * time;
        
        myBalls[i].setup(x, y, r);
        
        myBalls[i].vel.x = speed;
        myBalls[i].vel.y = speed;

        cout
        << "speed = " << speed <<" "
        << "radius = " << r
        << endl;
    }

    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i=0; i<50; i++){
        myBalls[i].update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i=0; i<50; i++) {

        myBalls[i].draw();
        
    }
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
