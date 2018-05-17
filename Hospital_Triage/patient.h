#pragma once
#include "ofMain.h"
#include <queue>

class Patient {
    
	public:
		int severity;
		int treatmentTimeNeeded;
		int treatmentRecieved;
		int lifeRemaining;
		float x;
		float y;
		ofColor color;

		Patient();
		Patient(float x, float y);

		void update();
		void draw();
        void treatment();
    
        struct PatientCompare
        {
            bool operator()(const Patient *patient1, const Patient *patient2) const
            {
                return patient1->severity < patient2->severity;
            }
        };
};
