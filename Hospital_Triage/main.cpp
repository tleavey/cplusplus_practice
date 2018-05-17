// Tim Leavey
// CS261: Final Project
// This program represents a hospital's emergency room.
// There is a waiting room and three doctors who can each treat a patient at a time.

#include "ofMain.h"
#include "ofApp.h"


//========================================================================
int main( ){
    
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
	ofRunApp(new ofApp());
    
}
