#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <typeinfo>

class DiscreteFiniteAutomaton {

public:
    std::vector<int> qListOfStates;
    std::vector<char> sigmaAlphabet;
    int qZeroInitialState = 1;
    std::vector<int> tAcceptingStates;
    std::vector<char> deltaTransitionFunctions;
    int currentState;
};

int main(int argc, char* argv[])
{
    // ===========================================================================================
    // PART 1: TAKING IN THE FILE AND SETTING VARIABLES TO THE DFA
    std::ifstream infile (argv[1]);
    if (argc < 2) {
        std::cout << "No file entered." << std::endl;
        return -1;
    } /*else {
        std::cout << "argc = " << argc << std::endl;
        std::cout << "argv[0] = " << argv[0] << std::endl;
        std::cout << "argv[1] = " << argv[1] << std::endl;
    } */
    // The DFA object.
    DiscreteFiniteAutomaton theDFA;
    std::string oneLine;
    int lineCounter = 1;
    // This while loop takes each line of the input file and reads it line by line.
    // Each if block within the while loop sets the appropriate variables to the DFA.
    while (std::getline(infile, oneLine))
    {
        std::istringstream iss(oneLine);
        // This IF block of code fills the states, Q, in the DFA.
        if (lineCounter == 1) {
            int n;
            while (iss >> n) {
                theDFA.qListOfStates.push_back(n);
            }
        }
        // This IF block of code fills the alphabet, sigma, in the DFA.
        if (lineCounter == 2) {
            char alphabet;
            while (iss >> alphabet) {
                theDFA.sigmaAlphabet.push_back(alphabet);
            }
        }
        // This IF block of code sets the initial state, q0, in the DFA.
        if (lineCounter == 3) {
            int initialState;
            while (iss >> initialState) {
                theDFA.qZeroInitialState = initialState;
            }
        }
        // This IF block of code sets the accepting states, T, in the DFA.
        if (lineCounter == 4) {
            int acceptingStates;
            while (iss >> acceptingStates) {
                theDFA.tAcceptingStates.push_back(acceptingStates);
            }
        }
        // This IF block of code fills the transition functions, delta, in the DFA.
        if (lineCounter > 4) {
            int arrayCounter = 0;
            char transitionFunction;
            //std::string varUsedToSplitForFuture = "-";
            while (iss >> transitionFunction) {
                theDFA.deltaTransitionFunctions.push_back(transitionFunction);
                /*
                arrayCounter += 1;
                if (arrayCounter % 3 == 0) {
                    theDFA.deltaTransitionFunctions.push_back(varUsedToSplitForFuture);

                }
                 */
            }
        }

        lineCounter += 1;
    }

    // ===========================================================================================
    // PART TWO: PRINTING THE CORRECT OUTPUT TO THE SCREEN BEFORE USER INPUT
    std::cout << "q0 = " << theDFA.qZeroInitialState;
    for (int j = 0; j < theDFA.tAcceptingStates.size(); ++j) {
        if (theDFA.qZeroInitialState == theDFA.tAcceptingStates[j]) {
            std::cout << "*";
        }
    }
    std::cout << std::endl;

    // This for loop prints out the transition functions, delta, with the correct formatting.
    // The inner for loop checks if the finishing state is an accepting state.
    // If it ends in an accepting state, an '*' is appended.
    for (int i = 0; i < theDFA.deltaTransitionFunctions.size(); i += 3) {
        std::cout << theDFA.deltaTransitionFunctions[i];
        std::cout << "," << theDFA.deltaTransitionFunctions[i + 1];
        std::cout << " -> " << theDFA.deltaTransitionFunctions[i + 2];
        for (int j = 0; j < theDFA.tAcceptingStates.size(); ++j) {
            if (((int)theDFA.deltaTransitionFunctions[i + 2]-48) == theDFA.tAcceptingStates[j]) {
                std::cout << "*";
            }
        }
        std::cout << std::endl;
    }
    /*  TESTING PURPOSES
    // TESTING THE CONTENTS OF DFA VARIABLES
    for (int i = 0; i < theDFA.qListOfStates.size(); ++i) {
        std::cout << theDFA.qListOfStates[i] << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < theDFA.sigmaAlphabet.size(); ++i) {
        std::cout << theDFA.sigmaAlphabet[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << theDFA.qZeroInitialState << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < theDFA.tAcceptingStates.size(); ++i) {
        std::cout << theDFA.tAcceptingStates[i] << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < theDFA.deltaTransitionFunctions.size(); ++i) {
        std::cout << theDFA.deltaTransitionFunctions[i] << " ";
    }*/

    // Asks the user for input
    std::cout << "Enter a string to check" << std::endl;
    std::string userInput;
    while (std::cin >> userInput) {
        // ===========================================================================================
        // PART THREE -- LOGIC OF DFA
        // Checks for correct/incorrect alphabet compared to user input.
        // Uses a bool flag to do this, while looping through both the user input and vector<char> alphabet.
        bool badInput = false;
        for (int i = 0; i < userInput.size(); ++i) {
            for (int j = 0; j < theDFA.sigmaAlphabet.size(); ++j) {
                if (userInput[i] == theDFA.sigmaAlphabet[j]) {
                    break;
                } else {
                    if (j == theDFA.sigmaAlphabet.size() - 1) {
                        badInput = true;
                    }
                }
            }
        }
        // If the user input contained letters not in the DFA alphabet, return error message.
        if (badInput == true) {
            std::cout << "Incorrect alphabet!";
            std::cout << std::endl;
            return -1;
        }
        // Set the current state to be the initial state and output it.
        theDFA.currentState = theDFA.qZeroInitialState;
        std::cout << theDFA.qZeroInitialState;
        // This for loop checks if the initial state is an accepting state, and if so,
        // appends an * at the end.
        for (int m = 0; m < theDFA.tAcceptingStates.size(); ++m) {
            if (theDFA.qZeroInitialState == theDFA.tAcceptingStates[m]) {
                std::cout <<  "*";
            }
        }
        // The next big chunk is the heart of the DFA where all the logic happens.
        bool inputIsValid = true;
        bool checkForAcceptingState = true;
        for (int i = 0; i < userInput.size(); ++i) {
            for (int j = 0; j < theDFA.deltaTransitionFunctions.size(); ++j) {
//                std::cout << "Entered j FOR loop." << std::endl;
//                std::cout << "j is: " << theDFA.deltaTransitionFunctions[j] << std::endl;
                if (checkForAcceptingState) {
                    if (theDFA.deltaTransitionFunctions[j] == userInput[i]) {
                        if ((int(theDFA.deltaTransitionFunctions[j - 1]) - 48) == theDFA.currentState) {
                            theDFA.currentState = (int(theDFA.deltaTransitionFunctions[j + 1]) - 48);
                            if (i == userInput.size() - 1) { // last letter entered if statement
//                                std::cout << "Entered last user input variable." << std::endl;
                                for (int m = 0; m < theDFA.tAcceptingStates.size(); ++m) {
//                                    std::cout << "Entered for last loop statement." << std::endl;
                                    if (theDFA.currentState == theDFA.tAcceptingStates[m]) {
                                        std::cout << " -> " << theDFA.currentState << "*";
                                        checkForAcceptingState = false;
//                                        std::cout << "ACCEPTED." << std::endl;
                                        break;
                                    } else {
                                        if ((m == theDFA.tAcceptingStates.size() - 1) && inputIsValid) {
                                            inputIsValid = false;
                                            std::cout << " -> " << theDFA.currentState;
//                                            std::cout << "REJECTED." << std::endl;
                                            break;
                                        }
                                    }
                                }
                            }
                            if (checkForAcceptingState && inputIsValid) {
                                // IT'S ENTERING THIS LOOP TOO MANY TIMES bcuz the userinput hasn't moved to the next letter yet.
                                // Wrong 'for loop' action. However, accepted/rejected states are still correct,
                                // but node output is slightly off by count.
                                std::cout << " -> " << theDFA.currentState;
                                for (int m = 0; m < theDFA.tAcceptingStates.size(); ++m) {
                                    if (theDFA.currentState == theDFA.tAcceptingStates[m]) {
                                        std::cout << "*";
                                    }
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (inputIsValid == true) {
            std::cout << std::endl;
            std::cout << "accepted" << std::endl;
        } else {
            std::cout << std::endl;
            std::cout << "rejected" << std::endl;
        }
    }
    return 0;
}


// Testing Purposes
//                std::cout << "SECOND for loop. TransFunc is = " << theDFA.deltaTransitionFunctions[j] << std::endl;
//                std::cout << userInput[i] << theDFA.deltaTransitionFunctions[j] << std::endl;
//                std::cout << "Type is: " << typeid(theDFA.deltaTransitionFunctions[j]).name() << std::endl;
//                std::cout << "Type is: " << typeid(userInput[i]).name() << std::endl;
//                    std::cout << "1st IF statement. userInput is equal to TransFunction" << std::endl;
//                    std::cout << "The current state is: " << theDFA.currentState << std::endl;
//                    std::cout << "TransFunc cast to int is: " << (int(theDFA.deltaTransitionFunctions[j - 1]) - 48) << std::endl;
//                            std::cout << "2nd IF statement. currentState is now: " << theDFA.currentState << std::endl;
//            std::cout << "FIRST for loop. userInput is = " << userInput[i] << std::endl;
//                                        std::cout << "INSIDE ACCEPTING STATE" << std::endl;
//                                            std::cout << "VALID FLAG SET TO FALSE" << std::endl;
//                                        std::cout << "rejected" << std::endl;

