#include "bounce_tra.h"

void Bounce_tra::setup(float posX, float posY, float _r){
    x = posX;
    y = posY;
    r = _r;
    
    dirX = 0;
    dirY = 0;
    color.set(ofRandom(255),ofRandom(255),ofRandom(255));
    
    
    
}

void Bounce_tra::update(){
    x += dirX;
    y += dirY;
    
    if (x > ofGetWidth()){
        x = ofGetWidth();
        dirX = dirX * -1;
        color.set(ofRandom(255),ofRandom(255),ofRandom(255));
        
    }else if (x < 0){
        x = 0;
        dirX = dirX * -1;
        color.set(ofRandom(255),ofRandom(255),ofRandom(255));
    }
    if (y > ofGetHeight()){
        y = ofGetHeight();
        dirY = dirY * -1;
        color.set(ofRandom(255),ofRandom(255),ofRandom(255));
        
    }else if (y < 0){
        y = 0;
        dirY = dirY * -1;
        color.set(ofRandom(255),ofRandom(255),ofRandom(255));
    }
    
    
    
}

void Bounce_tra::draw(){
    ofSetColor(color);
    ofDrawCircle(x, y, r);
    
    
}


