#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    vectorField = VectorField(50,50,ofGetWidth(),ofGetHeight());
    
    vectorField.setFieldNoisily(0.1);
    bDrawField = false;
    
    ball.setup();
    ball2.setup();
 
   
}

//--------------------------------------------------------------
void ofApp::update(){
    if (bAnimate)
        vectorField.setFieldNoisily(0.1);
    ball.update();
    glm::vec2 force = vectorField.getForceAtPos(ball.pos);
    ball.applyForce(force*1.5);
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    if (bDrawTrails){
        ofPushStyle();
        ofSetColor(0,0,0, 10);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        ofPopStyle();
    }
    if (bDrawField){
        vectorField.draw(80);
    }
    ball.draw();
   
   
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' '){
        bDrawField = true;
    }
    else if (key == 'a')
    {
        bAnimate = true;
    }
    else if (key == 't')
    {
        bDrawTrails = true;
        ofSetBackgroundAuto(false);
    }
    if( key == 's' ){
        ball.soundStream.start();
    }
    
    if( key == 'e' ){
        ball.soundStream.stop();
    }
 
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == ' '){
        bDrawField = false;
    }
    else if (key == 'a')
    {
        bAnimate = false;
    }
    else if (key == 't')
    {
        bDrawTrails = false;
        ofSetBackgroundAuto(true);
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    ball.vel.x += (x - ball.prev.x) / 20.0f;
    ball.vel.y += (y - ball.prev.y) / 20.0f;
    // store the previous mouse position:
    ball.prev.x = x;
    ball.prev.y = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
  
    ball.prev.x = x;
    ball.prev.y = y;
}


//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
// particleSystems.push_back( ParticleSystem(glm::vec2(x,y)) );
    ball2.setup();
    ball2.draw();
    
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
