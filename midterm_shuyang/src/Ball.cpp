//
//  Ball.cpp
//  midterm_shuyang
//
//  Created by 王舒阳 on 10/27/18.
//

#include "Ball.hpp"
void Ball::setup(){
    beat.load("sounds/jdee_beat.mp3");
    ow.load("sounds/ow.mp3");
    dog.load("sounds/dog.mp3");
    rooster.load("sounds/rooster.mp3");
    float radius;
    radius = scaledVol * 190.0f*2;
//    float px = ofRandom(0,ofGetWidth());
//    float py = ofRandom(0,ofGetHeight());
//    float vx = 0;
//    float vy = 0;
//    float prevx, prevy;
    
   glm::vec2 pos, vel, prev;
    
    pos  = glm::vec2(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()));
    vel = glm::vec2(0,0);
    
    
    ofSetVerticalSync(true);
    ofSetCircleResolution(80);
    ofBackground(54, 54, 54);
    
    soundStream.printDeviceList();
    
    int bufferSize = 256;
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    
    bufferCounter    = 0;
    drawCounter        = 0;
    smoothedVol     = 0.0;
    scaledVol        = 0.0;
    
    
    ofSoundStreamSettings settings;
    
    // if you want to set the device id to be different than the default
    // auto devices = soundStream.getDeviceList();
    // settings.device = devices[4];
    
    // you can also get devices for an specific api
    // auto devices = soundStream.getDevicesByApi(ofSoundDevice::Api::PULSE);
    // settings.device = devices[0];
    
    // or get the default device for an specific api:
    // settings.api = ofSoundDevice::Api::PULSE;
    
    // or by name
    auto devices = soundStream.getMatchingDevices("default");
    if(!devices.empty()){
        settings.setInDevice(devices[0]);
    }
    
    settings.setInListener(this);
    settings.sampleRate = 44100;
    settings.numOutputChannels = 0;
    settings.numInputChannels = 2;
    settings.bufferSize = bufferSize;
    soundStream.setup(settings);
    
    
    gravity = glm::vec2(0, .15);
}

//--------------------------------------------------------------
void Ball::update(){
    //lets scale the vol up to a 0-1 range
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    
    //lets record the volume into an array
    volHistory.push_back( scaledVol );
    
    //if we are bigger the the size we want to record - lets drop the oldest value
    if( volHistory.size() >= 400 ){
        volHistory.erase(volHistory.begin(), volHistory.begin()+1);
    }
    pos += vel;
    
    // (2) check for collision, and trigger sounds:
    // horizontal collisions:
    if (pos.x < 0){
        pos.x = 0;
        vel.x *= -1;
            // center screen
//        ParticleSystem particleSystem = ParticleSystem(pos);
//        particleSystem.applyForce(glm::vec2(0.15,0.15));
//        particleSystem.draw();
//        particleSystem.update(10,20);
        
        rooster.play();
        
    } else if (pos.x > ofGetWidth()){
        pos.x = ofGetWidth();
        vel.x *= -1;
           dog.play();
    }
    // vertical collisions:
    if (pos.y < 0 ){
        pos.y = 0;
        vel.y *= -1;
              rooster.play();
    } else if (pos.y > ofGetHeight()){
        pos.y = ofGetHeight();
        vel.y *= -1;
           dog.play();
    }
    // (3) slow down velocity:
    vel.x     *= 0.996f;
    vel.y     *= 0.996f;
    float time = ofGetElapsedTimef();
    if(time = 5){
        ofPushStyle();
        glm::vec2 pos1 = glm::vec2(glm::vec2(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight())));
        float rotation = ofRadToDeg(atan2(vel.y, vel.x));
        float hue = ofMap(rotation, -180,180, 0, 255, true);
        float sat = ofMap(glm::length(vel), 0, 10, 127.5, 255, true);
        float brt = 255;
        
        ofColor color = ofColor::fromHsb(hue-20,sat-20,brt-50);
        ofSetColor(color);
        ofFill();
        ofDrawCircle(pos1, scaledVol * 190.0f);
        ofPopStyle();
        
    }
//    if(scaledVol * 190.0f*1.5 > 30){
//        ParticleSystem particleSystem = ParticleSystem(pos);
//        particleSystem.applyForce(glm::vec2(0.15,0.15));
//        particleSystem.draw();
//        particleSystem.update(10,20);
//
//
//
//    }
    if(radius> 50){
        ofSetColor(144);
        ofNoFill();
        ofDrawTriangle(pos.x, pos.y, pos.x - 5, pos.y - 10, pos.x + 5, pos.y + 10);
    }
    
    
}

//--------------------------------------------------------------
void Ball::draw(){
    
    //    ofSetColor(225);
    //    ofDrawBitmapString("AUDIO INPUT EXAMPLE", 32, 32);
    //    ofDrawBitmapString("press 's' to unpause the audio\n'e' to pause the audio", 31, 92);
    //
    //    ofNoFill();
    //
    //    // draw the left channel:
    //    ofPushStyle();
    //        ofPushMatrix();
    //        ofTranslate(32, 170, 0);
    //
    //        ofSetColor(225);
    //        ofDrawBitmapString("Left Channel", 4, 18);
    //
    //        ofSetLineWidth(1);
    //        ofDrawRectangle(0, 0, 512, 200);
    //
    //        ofSetColor(245, 58, 135);
    //        ofSetLineWidth(3);
    //
    //            ofBeginShape();
    //            for (unsigned int i = 0; i < left.size(); i++){
    //                ofVertex(i*2, 100 -left[i]*180.0f);
    //            }
    //            ofEndShape(false);
    //
    //        ofPopMatrix();
    //    ofPopStyle();
    //
    //    // draw the right channel:
    //    ofPushStyle();
    //        ofPushMatrix();
    //        ofTranslate(32, 370, 0);
    //
    //        ofSetColor(225);
    //        ofDrawBitmapString("Right Channel", 4, 18);
    //
    //        ofSetLineWidth(1);
    //        ofDrawRectangle(0, 0, 512, 200);
    //
    //        ofSetColor(245, 58, 135);
    //        ofSetLineWidth(3);
    //
    //            ofBeginShape();
    //            for (unsigned int i = 0; i < right.size(); i++){
    //                ofVertex(i*2, 100 -right[i]*180.0f);
    //            }
    //            ofEndShape(false);
    //
    //        ofPopMatrix();
    //    ofPopStyle();
    
    // draw the average volume:
    //    ofPushStyle();
    //        ofPushMatrix();
    //        ofTranslate(565, 170, 0);
    //
    //        ofSetColor(225);
    //        ofDrawBitmapString("Scaled average vol (0-100): " + ofToString(scaledVol * 100.0, 0), 4, 18);
    //        ofDrawRectangle(0, 0, 400, 400);
    ofPushStyle();
    float rotation = ofRadToDeg(atan2(vel.y, vel.x));
    float hue = ofMap(rotation, -180,180, 0, 255, true);
    float sat = ofMap(glm::length(vel), 0, 10, 127.5, 255, true);
    float brt = 255;
    float radius;
    radius = scaledVol * 190.0f*1.5;
    ofColor color = ofColor::fromHsb(hue,sat,brt);
    ofSetColor(color);
    ofFill();
    ofDrawCircle(pos, radius);
    ofPopStyle();
    
    
    //lets draw the volume history as a graph
    //        ofBeginShape();
    //        for (unsigned int i = 0; i < volHistory.size(); i++){
    //            if( i == 0 ) ofVertex(i, 400);
    //
    //            ofVertex(i, 400 - volHistory[i] * 70);
    //
    //            if( i == volHistory.size() -1 ) ofVertex(i, 400);
    //        }
    //        ofEndShape(false);
    //
    //        ofPopMatrix();
    //    ofPopStyle();
    //
    //    drawCounter++;
    //
    //    ofSetColor(225);
    //    string reportString = "buffers received: "+ofToString(bufferCounter)+"\ndraw routines called: "+ofToString(drawCounter)+"\nticks: " + ofToString(soundStream.getTickCount());
    //    ofDrawBitmapString(reportString, 32, 589);
//    if(radius >50){
//        // center screen
//        ParticleSystem particleSystem = ParticleSystem(pos);
//        particleSystem.draw();
//        particleSystem.update();
//        
//        
//        
//    }

}

//--------------------------------------------------------------
void Ball::audioIn(ofSoundBuffer & input){
    
    float curVol = 0.0;
    
    // samples are "interleaved"
    int numCounted = 0;
    
    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    for (size_t i = 0; i < input.getNumFrames(); i++){
        left[i]        = input[i*2]*0.5;
        right[i]    = input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    
    //this is how we get the mean of rms :)
    curVol /= (float)numCounted;
    
    // this is how we get the root of rms :)
    curVol = sqrt( curVol );
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    
    bufferCounter++;
    
}

//--------------------------------------------------------------
void Ball::keyPressed  (int key){
    if( key == 's' ){
        soundStream.start();
    }
    
    if( key == 'e' ){
        soundStream.stop();
    }
}

//--------------------------------------------------------------
void Ball::keyReleased(int key){
    
}

//--------------------------------------------------------------
void Ball::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void Ball::mouseDragged1(){
    
    int _x;
    int _y;
    vel.x += (_x - prev.x) / 20.0f;
    vel.y += (_y - prev.y) / 20.0f;
    // store the previous mouse position:
    prev.x = _x;
    prev.y = _y;
}

//--------------------------------------------------------------
void Ball::mousePressed1(){
    
    int _x;
    int _y;
    prev.x = _x;
    prev.y = _y;
}

//--------------------------------------------------------------
void Ball::mouseReleased(int x, int y, int button){
//     particleSystems.push_back( ParticleSystem(glm::vec2(x,y)) );
    
}

//--------------------------------------------------------------

void Ball::applyForce(glm::vec2 force){
  vel.x += force.x;
    vel.y += force.y;
    
}

void Ball::applyDrag(float strength){
    vel.x *= 0.9;
    vel.y *= 0.9;
    
}

void Ball::part(glm::vec2 _pos){
//    Particle particle = Particle(_pos);
//            particle.applyForce(glm::vec2(0.15,0.15));
//            particle.draw();
//            particle.update();
    
    
    
    
    
}

