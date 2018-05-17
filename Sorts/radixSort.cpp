#include "sort.h"

// Prototypes -- Functions defined at bottom
int findMaximumValue(vector<int> v, int numberOfElements);
vector<int> combineBuckets(vector <int> &zero, vector <int> &one, vector <int> &two, vector <int> &three,
                           vector <int> &four, vector <int> &five, vector <int> &six, vector <int> &seven,
                           vector <int> &eight, vector <int> &nine, vector<int> &outputBucket);


void radixSort(vector <int> &v) {

    int numberOfElements = v.size() - 1;
    // The max value of the vector is stored in the maximumElement variable.
    int maximumValue = findMaximumValue(v, numberOfElements);

    // I realized that if only 0 is put into the list, with no other elements,
    // then my algorithm didn't work. With this if statement, it checks first to
    // see if 0 was the only input and returns if it is.
    if (maximumValue == 0) {
        return;
    }

    // loopsToGoThrough initially starts at 0, but by dividing the maximum value by 10
    // until it reaches 0 in a for loop, the number of divisions becomes the number of digits
    // in the maximum value.
    int loopsToGoThrough = 0;
    for (; maximumValue != 0;) {
        maximumValue /= 10;
        loopsToGoThrough += 1;
    }

    // shiftDigit will be used to shift left to the next digit
    int shiftDigit = 1;

    // 10 buckets for digit values of zero to nine
    vector<int> zero;
    vector<int> one;
    vector<int> two;
    vector<int> three;
    vector<int> four;
    vector<int> five;
    vector<int> six;
    vector<int> seven;
    vector<int> eight;
    vector<int> nine;
    vector<int> outputBucket;

    // This for loop iterates through however many digits the max number has.
    for (int i = 1; i <= loopsToGoThrough; ++i) {

        // This if statement checks to see if the outputBucket is empty
        // If it is not empty, vector v becomes the output version
        // This will happen through each iteration of the loop (but not the first time through).
        // The output bucket is then cleared so numbers can be combined into it again.
        if (!outputBucket.empty()) {
            v = outputBucket;
            outputBucket.clear();
        }
        // This for loop goes through each element and puts it in a new appropriate bucket
        // based on the digit it is looking at.
        for (int element = 0; element <= numberOfElements; ++element) {
            if (((v[element] / shiftDigit) % 10) == 0) {
                zero.push_back(v[element]);
            }
            if (((v[element] / shiftDigit) % 10) == 1) {
                one.push_back(v[element]);
            }
            if (((v[element] / shiftDigit) % 10) == 2) {
                two.push_back(v[element]);
            }
            if (((v[element] / shiftDigit) % 10) == 3) {
                three.push_back(v[element]);
            }
            if (((v[element] / shiftDigit) % 10) == 4) {
                four.push_back(v[element]);
            }
            if (((v[element] / shiftDigit) % 10) == 5) {
                five.push_back(v[element]);
            }
            if (((v[element] / shiftDigit) % 10) == 6) {
                six.push_back(v[element]);
            }
            if (((v[element] / shiftDigit) % 10) == 7) {
                seven.push_back(v[element]);
            }
            if (((v[element] / shiftDigit) % 10) == 8) {
                eight.push_back(v[element]);
            }
            if (((v[element] / shiftDigit) % 10) == 9) {
                nine.push_back(v[element]);
            }
        }
        combineBuckets(zero, one, two, three, four, five, six, seven, eight, nine, outputBucket);
        // The shiftDigit allows us to move to the next digit since we are using the decimal system.
        shiftDigit *= 10;
    }
    // Sets v as the final output bucket, which is fully sorted.
    v = outputBucket;
}

// This helper function finds the maximum value in the vector.
// By returning the max value, it can be used to determine how many digits I need to loop through.
int findMaximumValue(vector<int> v, int numberOfElements) {
    int maximumValue = v[0];
    // The max value starts at the first element and is compared with each other value.
    // If a value is greater than the current max, the max value is set to the new value.
    for (int i = 1; i <= numberOfElements; ++i) {
        if (v[i] > maximumValue) {
            maximumValue = v[i];
        }
    }
    return maximumValue;
}

// combineBuckets() combines zero thru nine buckets and pushes them into the output bucket.
// It checks if a bucket is empty, and if it's not, pushes the elements of that bucket
// into the output bucket. It then clears the original bucket of zero thru nine.
// (Does not clear the output bucket).

vector<int> combineBuckets(vector <int> &zero, vector <int> &one, vector <int> &two, vector <int> &three,
                           vector <int> &four, vector <int> &five, vector <int> &six, vector <int> &seven,
                           vector <int> &eight, vector <int> &nine, vector<int> &outputBucket) {

    if (!zero.empty()) {
        for (int i = 0; i < zero.size(); ++i) {
            outputBucket.push_back(zero[i]);
        }
        zero.clear();
    }
    if (!one.empty()) {
        for (int i = 0; i < one.size(); ++i) {
            outputBucket.push_back(one[i]);
        }
        one.clear();
    }
    if (!two.empty()) {
        for (int i = 0; i < two.size(); ++i) {
            outputBucket.push_back(two[i]);
        }
        two.clear();
    }
    if (!three.empty()) {
        for (int i = 0; i < three.size(); ++i) {
            outputBucket.push_back(three[i]);
        }
        three.clear();
    }
    if (!four.empty()) {
        for (int i = 0; i < four.size(); ++i) {
            outputBucket.push_back(four[i]);
        }
        four.clear();
    }
    if (!five.empty()) {
        for (int i = 0; i < five.size(); ++i) {
            outputBucket.push_back(five[i]);
        }
        five.clear();
    }
    if (!six.empty()) {
        for (int i = 0; i < six.size(); ++i) {
            outputBucket.push_back(six[i]);
        }
        six.clear();
    }
    if (!seven.empty()) {
        for (int i = 0; i < seven.size(); ++i) {
            outputBucket.push_back(seven[i]);
        }
        seven.clear();
    }
    if (!eight.empty()) {
        for (int i = 0; i < eight.size(); ++i) {
            outputBucket.push_back(eight[i]);
        }
        eight.clear();
    }
    if (!nine.empty()) {
        for (int i = 0; i < nine.size(); ++i) {
            outputBucket.push_back(nine[i]);
        }
        nine.clear();
    }
    return outputBucket;
}