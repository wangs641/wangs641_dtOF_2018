

#include "Particle.hpp"

Particle::Particle()
{
    
    // default constructor:
    // Particle particle = Particle();
    
    pos = glm::vec2(0,0);
    vel = glm::vec2(0,0);
    acc = glm::vec2(0,0);
}

Particle::Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass)
{
    
    // "overload" constructor, alternative:
    // Particle particle = Particle(pos,vel,acc);
    
    pos = _pos;
    vel = _vel;
    mass = _mass;
}

void Particle::applyForce(glm::vec2 force)
{
    acc += force / mass;
}

void Particle::update(glm::vec2 target)

{
    
    float time = ofGetElapsedTimef();
    
    pos.y += vel.y;
       
    if(time > 2){
    vel += acc;
    pos += vel;
        acc *= 0;}///////
    glm::vec2 direction = target - pos;
    pos += (direction) * .03;
    float angleRadians = atan2(direction.y, direction.x);
    angle = ofRadToDeg(angleRadians);
    
    atan2(pos.y, pos.x);
    angle = atan2(pos.y, pos.x);
   
    
    
    
}

    
    
    


void Particle::draw()
{float col ;
    col = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255);
    ofPushStyle();
    float hue = ofMap(mass, 0, 5, 0, 255);
//    ofSetColor(ofColor::fromHsb(hue,col,255));
    ofSetColor(hue, 168, col);
    ofDrawCircle(pos, mass * 2.0);
    ofPopStyle();
}

