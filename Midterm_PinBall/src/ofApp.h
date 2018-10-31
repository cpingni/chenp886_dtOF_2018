#pragma once

#include "ofMain.h"
#include "Ball.hpp"
#include "PaddleL.hpp"
#include "PaddleR.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    Ball ball;
    PaddleL paddleL;
    PaddleR paddleR;
    
    ofColor paddleColor, ballColor, obColor;
    int rotateAngleR, rotateAngleL;
    
    glm::vec2 ob1Pos, ob2Pos, ob3Pos, ob4Pos, ob5Pos;

    ofSoundPlayer ding;
    
    
    
};
