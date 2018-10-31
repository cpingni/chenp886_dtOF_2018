#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    ofBackground(150);
    ofSetCircleResolution(100);
    
    ////////////// pinball //////////////
    glm::vec2 ballPos = glm::vec2 (ofGetWidth()*0.5, 50);
    ball.setup(ballPos,20);
    
    ///////////// obstacles //////////////
    ob1Pos = glm::vec2(ofGetWidth()*0.5 - 200,300);
    ob2Pos = glm::vec2(ofGetWidth()*0.5,500);
    ob3Pos = glm::vec2(ofGetWidth()*0.5 + 200,300);
    ob4Pos = glm::vec2(0,500);
    ob5Pos = glm::vec2(ofGetWidth(),500);
    
    
    ////////// both paddles ////////////
    glm::vec2 paddleLPos = glm::vec2(ofGetWidth()*0.5 -200,750);
    glm::vec2 paddleRPos = glm::vec2(ofGetWidth()*0.5 +200,750);

    float angle = 0.;
    
    paddleL = PaddleL(paddleLPos, 0.);
    paddleR = PaddleR(paddleRPos, 0.);
    
    ding.load("ting.WAV");
    


}

//--------------------------------------------------------------
void ofApp::update(){
    
    ///////////// ball bouncing in canvas ////////////
    ball.update();
    
    /////////////// paddle rotating ///////////////
    if (rotateAngleR != 0){
        paddleR.rotate(rotateAngleR);
    }
    if (rotateAngleL != 0){
        paddleL.rotate(rotateAngleL);
    }
    ///////////// obstacle collision ////////////
    glm::vec2 diff1 = ob1Pos - ball.pos;
    glm::vec2 diff2 = ob2Pos - ball.pos;
    glm::vec2 diff3 = ob3Pos - ball.pos;
    glm::vec2 diff4 = ob4Pos - ball.pos;
    glm::vec2 diff5 = ob5Pos - ball.pos;
    bool ob1Collided = glm::length(diff1) <= 60 + ball.radius;
    bool ob2Collided = glm::length(diff2) <= 40 + ball.radius;
    bool ob3Collided = glm::length(diff3) <= 60 + ball.radius;
    bool ob4Collided = glm::length(diff4) <= 80 + ball.radius;
    bool ob5Collided = glm::length(diff5) <= 80 + ball.radius;
    if (ob1Collided) {
        obColor = ofColor(200,80,100);
        ding.play();
        ball.speed.y *= -1;
    } else {
         obColor = ofColor(ofNoise(100,255), ofRandom(100,255),ofRandom(100,255));
    }
    if (ob2Collided) {
        obColor = ofColor(200,80,100);
        ding.play();
        ball.speed.y *= -1;
    } else {
        obColor = ofColor(ofNoise(100,255), ofRandom(100,255),ofRandom(100,255));
    }
    
    if (ob3Collided) {
        obColor = ofColor(200,80,100);
        ding.play();
        ball.speed.y *= -1;
    } else {
        obColor = ofColor(ofNoise(100,255), ofRandom(100,255),ofRandom(100,255));
    }
    if (ob4Collided) {
        obColor = ofColor(200,80,100);
        ding.play();
        ball.speed.y *= -1;
    } else {
        obColor = ofColor(ofNoise(100,255), ofRandom(100,255),ofRandom(100,255));
    }
    if (ob5Collided) {
        obColor = ofColor(200,80,100);
        ding.play();
        ball.speed.y *= -1;
    } else {
        obColor = ofColor(ofNoise(100,255), ofRandom(100,255),ofRandom(100,255));
    }
    
    
    ////////// check paddle collision ////////////
    
    bool paddleCollidedR = paddleR.checkCollision(ball.pos,    ball.radius);
    bool paddleCollidedL = paddleL.checkCollision(ball.pos,ball.radius);
    
    
    if (paddleCollidedR || paddleCollidedL) {
        paddleColor = ofColor(200,80,100);
        ding.play();
        ball.speed.y *= -1;
        
    } else {
        paddleColor = ofColor(100,255,200);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushStyle();
    ofSetColor(paddleColor);
    paddleL.draw();
    paddleR.draw();
    ofPopStyle();
    
    ofSetColor(obColor);
    ofDrawCircle(ob1Pos,60);
    ofDrawCircle(ob2Pos,40);
    ofDrawCircle(ob3Pos,60);
    ofDrawCircle(ob4Pos,80);
    ofDrawCircle(ob5Pos,80);
    

    ofSetColor(ballColor);
    ball.draw();

    
    ofSetColor(80);
    
    
/////////////// instruction /////////////
    ofDrawBitmapString("Press w/s to control the Left Paddle", 20, 20);
    ofDrawBitmapString("Press o/k to control the Right Paddle", 20, 40);
    ofDrawBitmapString("Press SPACE to reset", 20, 60);
    
/////////////// Lives /////////////
    ofDrawBitmapString( "Lives:" + ofToString(ball.lives) , 600, 60);
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == 'o'){
        rotateAngleR = 10;
    }
    else if (key == 'k'){
        rotateAngleR = -10;
    }
    
    if (key == 'w'){
        rotateAngleL = -10;
    }
    else if (key == 's'){
        rotateAngleL = 10;
    }

    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    if (key == 'o' || key == 'k'){
        rotateAngleR = 0;
    }
    if (key == 'w' || key == 's'){
        rotateAngleL = 0;
    }
    if(key == ' '){
        ball.reset();
    }

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
