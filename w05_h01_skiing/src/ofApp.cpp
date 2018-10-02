#include "ofApp.h"

//--------------------------------------------------------------

//skiingggggggggggggggggggggg

void ofApp::setup(){
    ofBackground(0);
    pos = glm::vec2(0, 0);
    pos2 = glm::vec2(ofGetWidth()*0.5,0);
}

//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef();
    

    
    sinFrequency = 1;
    cosFrequency = 4;
    float ski1Sin = sin(time * sinFrequency) * 1;
    //increase frequecy by [time] *2
    //modify amplitude by [sin(time)] * 2
    float ski1Cos = cos(time * cosFrequency) * 0.3;

    pos.y = ofMap(ski1Sin, 1, -1, 0, ofGetHeight());
    //because sin always output to 1, -1; so map it out to fit the screen
    pos.x = ofMap(ski1Cos, -1, 1, ofGetHeight(), 0);

    trail.addVertex(pos.x, pos.y);
    
    
    sinFrequency = 1;
    cosFrequency = 8;
    float ski2Sin = sin(time * sinFrequency) * 1;
    float ski2Cos = cos(time * cosFrequency) * 0.1;
    
    pos2 = glm::vec2(pos2.x,pos2.y);
    pos2.y = ofMap(ski2Sin, 1, -1, 0, ofGetHeight());
    pos2.x = ofMap(ski2Cos, -1, 1, ofGetHeight(), 0);
    
    trail2.addVertex(pos2.x, pos2.y);


}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofDrawBitmapString("Click to clear trail", 30, 30);
    ofSetColor(100,200,200);
    ofSetLineWidth(1.5);
    trail.draw();
    
    ofSetColor(255);
    ofDrawCircle(pos,10);
    
    ofTranslate(300,0);
    trail2.draw();
    ofSetColor(255);
    ofDrawCircle(pos2,10);
    
    

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
    trail.clear();
    trail2.clear();
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
