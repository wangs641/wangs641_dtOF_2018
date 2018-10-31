//
//  Ball.hpp
//  midterm_shuyang
//
//  Created by 王舒阳 on 10/27/18.
//

#pragma once
#include "ofMain.h"
#include "ParticleSystem.hpp"
#include "Particle.hpp"

class Ball {
    
public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged1();
    void mousePressed1();
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void audioIn(ofSoundBuffer & input);
    void applyForce(glm::vec2 force);
    void applyDrag(float strength);
    void bounceWalls(float left, float right, float top, float bottom, float front, float back);
    void part(glm::vec2 _pos);
    
    
    vector <float> left;
    vector <float> right;
    vector <float> volHistory;
    
    int     bufferCounter;
    int     drawCounter;
    
    float smoothedVol;
    float scaledVol;
    
    ofSoundStream soundStream;
    
//    float px = ofRandom(0,ofGetWidth());
//    float py = ofRandom(0,ofGetHeight());
//    float vx = 0;
//    float vy = 0;
//    float prevx, prevy;
    
    glm::vec2 pos, vel, prev, _pos, _vel;
    float radius;
    ParticleSystem particleSystem;
    glm::vec2 gravity;
    ofSoundPlayer         beat;
    
    ofSoundPlayer        ow;
    ofSoundPlayer        dog;
    ofSoundPlayer        rooster;

    
};
