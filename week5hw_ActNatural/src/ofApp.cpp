#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(100);
    lerp = 0.05;
    
   
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    glm::vec2 mouse;
    mouse.x = ofGetMouseX();
    mouse.y = ofGetMouseY();
    pos += (mouse - pos)*lerp;
}

//--------------------------------------------------------------
void ofApp::draw(){
    m = ofMap(ofGetMouseX(),0,ofGetWidth(), 0,255);
    n = ofMap(ofGetMouseY(),0,ofGetHeight(), 0,255);
    ofBackground(m, 5, 3);
    
    ofSetColor(n, 234, 39);
    ofDrawEllipse(pos.x, pos.y, 300, 300);
    
    
    ofSetColor(255);
    ofDrawEllipse(pos.x-40, pos.y-30, 70, 50);
    
    ofSetColor(255);
    ofDrawEllipse(pos.x+40, pos.y-30, 70, 50);
    
    
    float time =ofGetElapsedTimef();
    float cosOfTime = cos(time);
    pos1.x = ofMap(cosOfTime, -1, 1, pos.x-10,pos.x);
    
    float sinOfTime = sin(time);
    pos1.y = ofMap(sinOfTime, -1, 1, pos.y-5, pos.y);
    //    pos.x = ofMap(sin(time), -1, 1, 0, ofGetHeight());
    
    pos1.x += ofSignedNoise(time)*40;
    pos1.y += ofSignedNoise(time + 100)*40;
    
    float time1 =ofGetElapsedTimef()+20;
    float cosOfTime1 = sin(time1);
   
    
    float sinOfTime1 = cos(time1);
     pos2.x = ofMap(sinOfTime1, -1, 1, pos.x-10,pos.x);
    pos2.y = ofMap(cosOfTime1, -1, 1, pos.y-5, pos.y);
    //    pos.x = ofMap(sin(time), -1, 1, 0, ofGetHeight());
    
    pos2.x += ofSignedNoise(time)*40;
    pos2.y += ofSignedNoise(time + 100)*40;
    
    
    
    ofSetColor(0);
    ofDrawEllipse(pos1.x-40, pos1.y-30, 20, 20);
    
    ofSetColor(0);
    ofDrawEllipse(pos2.x+40, pos2.y-30, 20, 20);
    
    
    
//    ofSetColor(0);
//    ofDrawEllipse(pos.x-40, pos.y-30, 20, 20);
//
//    ofSetColor(0);
//    ofDrawEllipse(pos.x+40, pos.y-30, 20, 20);
//
    
    
    
    
    ofSetColor(184,m,m);
    ofDrawTriangle(pos.x, pos.y, pos.x-20, pos.y+20, pos.x+20, pos.y+20);
    
    ofSetColor(255);
    ofDrawRectangle(pos.x-40, pos.y+40, 80, 20);
    
    ofSetColor(0);
    ofDrawLine(pos.x-40, pos.y+50, pos.x+40, pos.y+50);
    ofDrawLine(pos.x-20, pos.y+40, pos.x-20, pos.y+60);
    ofDrawLine(pos.x, pos.y+40, pos.x, pos.y+60);
    ofDrawLine(pos.x+20, pos.y+40, pos.x+20, pos.y+60);
    
    
    
    

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
