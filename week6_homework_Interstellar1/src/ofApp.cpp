#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    float numMax = 500;
    ofBackground(0);
//    glm::vec2 pos = glm::vec2(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
//
//    glm::vec2 vel = glm::vec2(ofRandom(-1,5));
//    float mass = ofRandom(-0.5, 5);
    for(int i =0; i<numMax; i++){
        
    
        Intersellar intersellar  = Intersellar(glm::vec2(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), glm::vec2(ofRandom(-1,5)), ofRandom(-0.1, 5));
        intersellars.push_back(intersellar);
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
    glm::vec2 mousePos = glm::vec2(
                                   ofGetMouseX(), ofGetMouseY());
    
    for (int i=0; i<intersellars.size(); i++){
        
        glm::vec2 attraction, repulsion;
        
        glm::vec2 dir = mousePos - intersellars[i].pos;
        
        float distance = glm::length(dir);
        
        if (distance > 0) {
            
            glm::vec2 normalizedDir = dir / distance;
            
            
            if (distance < 300) {
                
                repulsion = -normalizedDir;
                
            } else if ( distance < 500) {
                
                attraction = normalizedDir;
            }
        }
        
        intersellars[i].addForce(attraction);
        intersellars[i].addForce(repulsion);
        intersellars[i].applyDamping(0.05);
        intersellars[i].update();
        
        

    }}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    for(int i = 0; i<intersellars.size(); i++){
        float mousePos =ofGetMouseX();
        float dist = mousePos - intersellars[i].pos.x;
        float cl = ofMap(dist, 0, ofGetWidth(), 0, 255);
        
        
        intersellars[i].draw(cl);
    }
}

