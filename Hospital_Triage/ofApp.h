#pragma once

#include "ofMain.h"
#include "patient.h"
#include "doctor.h"
#include <queue>
#include <vector>

class ofApp : public ofBaseApp {

	public:
        priority_queue<Patient*, vector<Patient*>, Patient::PatientCompare> waitingRoom;
        vector<Patient*> waitingRoomVector;
        vector<Doctor*> doctorOffices;
    
        void setup();
		void update();
		void draw();
    
        Doctor doctor1 = Doctor(875,125);
        Doctor doctor2 = Doctor(875,325);
        Doctor doctor3 = Doctor(875,525);

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);		
};


