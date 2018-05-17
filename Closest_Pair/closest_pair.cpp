// Tim Leavey
// CS 325: Analysis of Algorithms
// Homework #1 - Closest Pair 1D

#include <iostream>
#include <vector>
#include <string>

// Class for recursive function
class ClosestPair {
    public:
        int x = 0;
        int y = 0;
        int distance;
};

// Function Prototypes
void bruteForcePair(std::vector<int> lineOfPoints);
ClosestPair recursiveCP(std::vector<int> lineOfPoints);


int main() {

    std::vector<int> lineOfPoints;
    int point;

    // User input goes into the vector
    while (std::cin >> point) {
        lineOfPoints.push_back(point);
    }
    // Guards against user input that has less than 2 inputs.
    if (lineOfPoints.size() >= 2) {
        // The brute force method is called.
        bruteForcePair(lineOfPoints);

        // The recursive method is called.
        ClosestPair recursion = recursiveCP(lineOfPoints);
        std::cout << "Recursive Closest Pair: " << "(" + std::to_string(recursion.x) + "," + std::to_string(recursion.y)+ ")";

    } else {
       std::cout << "At least 2 points must be entered." << std::endl;
    }
    return 0;
}

// Functions

// Brute Force method of finding closest pairs
void bruteForcePair(std::vector<int> lineOfPoints) {
    std::sort(lineOfPoints.begin(), lineOfPoints.end());
    int point1 = lineOfPoints[0];
    int point2 = lineOfPoints[1];
    int xCoordinate = point1;
    int yCoordinate = point2;
    int distance = point2 - point1;

    for (int i = 0, j = 1; i < lineOfPoints.size() - 1; ++i, ++j) {
        point1 = lineOfPoints[i];
        point2 = lineOfPoints[j];
        if (point2 - point1 < distance) {
            distance = point2 - point1;
            xCoordinate = point1;
            yCoordinate = point2;
        }
    }
    std::cout << "Brute Force Closest Pair: " << "(" << xCoordinate << "," << yCoordinate << ")" << std::endl;
}

// Recursive method for closest pair
ClosestPair recursiveCP(std::vector<int> lineOfPoints) {
    std::sort(lineOfPoints.begin(), lineOfPoints.end());

    if (lineOfPoints.size() == 2) {
        ClosestPair cpObject;
        cpObject.x = lineOfPoints[0];
        cpObject.y = lineOfPoints[1];
        cpObject.distance = lineOfPoints[1] - lineOfPoints[0];
        return cpObject;
    }

    // Intention: ClosestPair left = recursiveCP(lineOfPoints[0 thru size/2]);
    // So split the vector in two parts in order to put into the recursive function
    std::vector<int> subvectorLeft;
    for (int i = 0; i <= lineOfPoints.size()/2; ++i) {
        subvectorLeft.push_back(lineOfPoints[i]);
    }

    // Intention: ClosestPair right = recursiveCP(lineOfPoints[size/2 thru last]);
    std::vector<int> subvectorRight;
    for (int j = lineOfPoints.size()/2; j < lineOfPoints.size(); ++j) {
        subvectorRight.push_back(lineOfPoints[j]);
    }

    ClosestPair left = recursiveCP(subvectorLeft);
    ClosestPair right = recursiveCP(subvectorRight);

    // Compares the final distances of the final 2 pairs and returns the one with less distance between
    if (left.distance < right.distance) {
        return left;
    } else {
        return right;
    }
}