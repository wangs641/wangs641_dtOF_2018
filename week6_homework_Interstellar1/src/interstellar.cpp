//
//  interstellar.cpp
//  myGrandSketch
//
//  Created by 王舒阳 on 10/9/18.
//

#include "interstellar.hpp"


Intersellar::Intersellar(){
    pos = glm::vec2( ofRandom(
                              ofGetWidth()), ofRandom(ofGetHeight()));
    mass = ofRandom(0.5, 5);
    vel = glm::vec2(0,0);
    acc = glm::vec2(0,0);
    
}
Intersellar::Intersellar(glm::vec2 _pos, glm::vec2 _vel, float _mass){
    pos = _pos;
    mass = _mass;
    
    vel = glm::vec2(0,0);
    acc = glm::vec2(0,0);
    
    
}
void Intersellar::addForce(glm::vec2 force){
    acc += force/mass;
}

void Intersellar::applyDamping(float strength){
    float length = glm::length(vel);
    if(length != 0){
        glm::vec2 direction = vel/length;
        addForce( -direction * strength);
        
    }
    
    
    
    
    
    
    
    
}

void Intersellar::update(){
    
    vel += acc;
    pos+= vel;
    
    acc *= 0;
    
}

void Intersellar::draw(float cl){
    ofPushStyle();
    
    ofSetColor(80, cl, cl);
    ofDrawCircle(pos, mass*3.0);
    ofPopStyle();
    
}

