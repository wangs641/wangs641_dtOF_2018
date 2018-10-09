//
//  interstellar.hpp
//  myGrandSketch
//
//  Created by 王舒阳 on 10/9/18.
//





#pragma once
#include "ofMain.h"

class Intersellar{
public:
    Intersellar();
    Intersellar(glm::vec2 _pos, glm::vec2 _vel, float  _mass);
    void draw(float cl);
    void update();
    
    void addForce(glm::vec2 force);
    void applyDamping(float strength);
    
    glm::vec2 pos, vel, acc;
    float mass;
    
    
    
    
};
