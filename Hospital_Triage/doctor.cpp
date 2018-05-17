#include "ofMain.h"
#include "doctor.h"

Doctor::Doctor(float x, float y) {
    this->x = x;
    this->y = y;
    color = ofColor(255, 255, 255, 255);
}

void Doctor::draw() {
    ofSetColor(color);
    ofSetCircleResolution(125);
    ofDrawCircle(x, y, 40);
    ofSetColor(ofColor::black);
    ofDrawBitmapString("DOCTOR", x-25, y+5);
    if (patient != NULL) {
        patient->draw();
    }
}

void Doctor::movePatient() {
    if (this->patient != NULL) {
        this->patient->x = 675;
        this->patient->y = 125;
    }
}

void Doctor::movePatient(float x, float y) {
    if (this->patient != NULL) {
        this->patient->x = x - 200;
        this->patient->y = y;
    }
}

void Doctor::backToWaitingRoom() {
    if (this->patient != NULL) {
        this->patient->x = ofRandom(50, 500);
        this->patient->y = ofRandom(100, 600);
    }
}
