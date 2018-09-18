#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    for(int i = 0; i < 20; i++){
     
        float r = 10;
        float x = i *50;
        float y = i *60;
        ball[i].setup(x, y, r);
        ball[i].dirX = 5 * i * 0.1;
        ball[i].dirY = 6 * i * 0.1;
        
        
    
    
    
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i = 0; i < 20; i ++){
    
    
        ball[i].update();}
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i < 20; i ++){
        
        
        ball[i].draw();}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'a'|| key == 'A'){
        for(int i = 0; i < 20 ; i ++ ){
            ball[i].r = 50;
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 'a'|| key == 'A'){
        for(int i = 0; i < 20 ; i ++ ){
            ball[i].r = 10;
        }
    }

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
