
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(100);
    
    posR = glm::vec2(ofGetWidth()*0.5 -50,100);
    posL = glm::vec2(ofGetWidth()*0.5 +50,100);
    eyeColor = ofColor(255);
    myPupils.setup();
    ofSetCircleResolution(100);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    myPupils.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    //eye
    ofSetColor(eyeColor);
    ofDrawCircle(posR.x,posR.y,30);
    ofDrawCircle(posL.x,posL.y,30);
    ofSetColor(255);
    myPupils.draw();
    ofSetColor(255);
    //nose
    glm::vec2 noseTop;
    glm::vec2 noseBott;
    noseTop = glm::vec2 (ofGetWidth()*0.5,100);
    noseBott = glm::vec2 (ofGetWidth()*0.5,150);
    //mouth
    ofDrawLine(noseTop,noseBott);
    ofSetColor(mouthA,mouthB,ofNoise(255));
    mouthA = ofMap(ofGetMouseX(),0,ofGetWidth(),0,255 );
    mouthB = ofMap(ofGetMouseY(),0,ofGetHeight(),0,255 );
    ofDrawRectangle(ofGetWidth()*0.5-75, 180 , 150, 10);


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
