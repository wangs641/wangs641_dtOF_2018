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
    
       ofSetColor(0);
    ofDrawEllipse(pos.x-40, pos.y-30, 20, 20);
    
    ofSetColor(0);
    ofDrawEllipse(pos.x+40, pos.y-30, 20, 20);
    
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
