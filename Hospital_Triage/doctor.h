#pragma once
#include "ofMain.h"
#include "patient.h"

class Doctor {
    
    public:
        float x;
        float y;
        ofColor color;
    
        Patient* patient = NULL;
    
        Doctor(float x, float y);
    
        void draw();
        void movePatient();
        void movePatient(float x, float y);
        void backToWaitingRoom();
};
