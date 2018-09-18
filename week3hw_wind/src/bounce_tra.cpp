#include "bounce_tra.h"

void Bounce_tra::setup(float posX, float posY, float _r){
    x = posX;
    y = posY;
    r = _r;
    
    dirX = 0;
    dirY = 0;
    color.set(ofRandom(255),ofRandom(255),ofRandom(255));
    acc.x = 0;
    acc.y = -0.2;
    
    
    
}

void Bounce_tra::update(){
   float time = ofGetElapsedTimef();
    if (time < 1.5){
    dirX += (acc.x * time*0.8);
    dirY += (acc.y * time*0.8);
    x += dirX;
        y += dirY;}
  if (time > 1.5||time <4){
       dirX -= (acc.x * time*0.8);
       dirY -= (acc.y * time*0.8);
        x += dirX;
      y += dirY;}
    if (time >4){
        dirX -= (acc.x * time*0.1);
        dirY -= (acc.y * time*0.1);
        
        y += dirY;}
    
 
    

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


