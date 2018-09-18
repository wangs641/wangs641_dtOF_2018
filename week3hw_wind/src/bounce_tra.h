#pragma once
#include "ofMain.h"

class Bounce_tra {
public:
    
    void setup (float posX,  float posY, float _r);
    void update();
    void draw();
    
    float x, y, r;
    ofColor color;
    float dirX, dirY;
    glm::vec2 acc;
    float time;
    
    
    
    
    
    
};
