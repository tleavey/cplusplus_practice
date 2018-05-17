#include "ofMain.h"
#include "patient.h"

Patient::Patient() {
	x = ofRandom(50, 250);
	y = ofRandom(125, 600);
    severity = ofRandom(1, 11);
	lifeRemaining = ofRandom(10000);
    treatmentTimeNeeded = ofRandom(1300);
    treatmentRecieved = 0;
	color = ofColor(ofRandom(25, 255), ofRandom(25, 255), ofRandom(25, 255), 150);
}

Patient::Patient(float x, float y) {
	this->x = x;
	this->y = y;
    severity = ofRandom(1, 11);
	lifeRemaining = ofRandom(10000);
    treatmentTimeNeeded = ofRandom(1200);
    treatmentRecieved = 0;
    color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255), 150);
}

void Patient::draw() {
	ofSetColor(color);
	ofSetCircleResolution(125);
	ofDrawCircle(x, y, 30);
	ofSetColor(ofColor::white);
	ofDrawBitmapString("Life remaining: " + to_string((lifeRemaining)), x-15, y-15);
    ofDrawBitmapString("Severity: " + to_string((severity)), x-15, y);
    ofDrawBitmapString("Treatment Needed: " + to_string((treatmentTimeNeeded)), x-15, y+15);
    ofDrawBitmapString("Treatment Received: " + to_string((treatmentRecieved)), x-15, y+30);
}

void Patient::update() {
    if (this->lifeRemaining > 0) {
        this->lifeRemaining -= 1;
        if (this->lifeRemaining < 200) {
            this->severity += this->lifeRemaining;
        }
    }
}

void Patient::treatment() {
    this->treatmentRecieved += 1;
    if (this->lifeRemaining > 0) {
        this->lifeRemaining -= 1;
    }
}
