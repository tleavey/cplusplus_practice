// Turns an unsigned number to binary number
#include <iostream>

using namespace std;

void decimalToBinary(unsigned decNumber) {
    char bit16[]  = "0000000000000000";
    unsigned originalNum = decNumber;
    for (int index = 15; index >= 0; --index)
    {
        if (decNumber % 2)
            bit16[index] = '1';
        decNumber /= 2;
    }
}


int main()
{
    unsigned decimalNumber;
    cout << "Enter a positive integer to be converted into binary: ";
    cin >> decimalNumber;

    if (decimalNumber < 0) {
        cout << "Number must be a positive integer.";
    } else if (decimalNumber > 65535) {
        cout << "Number must be less than 65536.";
    } else {
        decimalToBinary(decimalNumber);
    }
}
