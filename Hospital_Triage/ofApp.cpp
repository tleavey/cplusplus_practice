#include "ofApp.h"
#include "patient.h"
#include "doctor.h"

int death_count = 0;
int patients_healed = 0;
int total_patients = 0;

//--------------------------------------------------------------
void ofApp::setup() {
    
    ofSetBackgroundColor(15);
    doctorOffices.push_back(&doctor1);
    doctorOffices.push_back(&doctor2);
    doctorOffices.push_back(&doctor3);
}

//--------------------------------------------------------------
void ofApp::update() {
    
	ofLog(OF_LOG_NOTICE, "%llu", ofGetFrameNum());
	if (ofGetFrameNum() % 100 == 0) {
		float prob = ofRandom(1.0);
		if (prob < 0.5){
            Patient *injuredPerson = new Patient();
            total_patients += 1;
            waitingRoom.push(injuredPerson);
            ofLog(OF_LOG_NOTICE, "NEW PATIENT!");
		}
	}
    
    for (Doctor* doctor : doctorOffices) {
        if (doctor->patient == NULL) {
            if (waitingRoom.empty() == false) {
                doctor->patient = waitingRoom.top();
                waitingRoom.pop();
                doctor->movePatient(doctor->x, doctor->y);
                ofLog(OF_LOG_NOTICE, "With Doctor!");
            }
        } else {
            if (waitingRoom.empty() == false) {
                if (waitingRoom.top()->severity > doctor->patient->severity) {
                    waitingRoom.push(doctor->patient);
                    doctor->backToWaitingRoom();
                    doctor->patient = waitingRoom.top();
                    waitingRoom.pop();
                    doctor->movePatient(doctor->x, doctor->y);
                    ofLog(OF_LOG_NOTICE, "Changed With Doctor!");
                }
            }
        }
        if (doctor->patient != NULL) {
            doctor->patient->treatment();
            if (doctor->patient->treatmentTimeNeeded <= doctor->patient->treatmentRecieved) {
                patients_healed += 1;
                doctor->patient = NULL;
            } else if (doctor->patient->lifeRemaining <= 0) {
                doctor->patient = NULL;
                death_count += 1;
            }
        }
    }
    
    while (waitingRoom.empty() == false) {
        waitingRoomVector.push_back(waitingRoom.top());
        waitingRoom.pop();
    }

    for (Patient* patient : waitingRoomVector) {
        patient->update();
        if (patient->lifeRemaining > 0) {
            waitingRoom.push(patient);
        } else {
            death_count += 1;
            ofLog(OF_LOG_NOTICE, "Patient expired!");
        }
    }
    
    waitingRoomVector.clear();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255, 255, 255, 255);
    ofDrawLine(620, 0, 620, 768);
    ofDrawLine(620, 70, 1024, 70);
    
    for (Doctor* doctor : doctorOffices) {
        doctor->draw();
    }
    
    while (waitingRoom.empty() == false) {
        waitingRoomVector.push_back(waitingRoom.top());
        waitingRoom.pop();
    }
    
    for (Patient* patient : waitingRoomVector) {
        patient->draw();
        waitingRoom.push(patient);
    }
    
    waitingRoomVector.clear();
    
    ofSetColor(ofColor::indianRed);
    ofDrawBitmapString("Patients Expired: " + to_string((death_count)), 700, 30);
    ofDrawBitmapString("Patients Saved: " + to_string((patients_healed)), 700, 15);
    ofDrawBitmapString("Patients Waiting: " + to_string((waitingRoom.size())), 700, 45);
    ofDrawBitmapString("Total Patients: " + to_string((total_patients)), 700, 60);
    ofDrawBitmapString("Waiting Room", 250, 15);
    ofDrawBitmapString("Emergency Room", 750, 670);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}
