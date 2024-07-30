#include <bits/stdc++.h>

using namespace std;

// This checks if the string contains all characters from 0 to 9 (character validity)
bool areAllnum(const string &s) {
    for (char c : s) {
        if (!isdigit(c))  // Using isdigit for character validity
            return false;
    }
    return true;
}

// This checks the length of number entered (it should be between 13 to 16) (size validity)
bool sizeValidity(const string &s) {
    return s.length() >= 13 && s.length() <= 16;  // Corrected the logic
}

int main() {
    cout << "*************************************************************************" << endl;
    cout << "                Validate Credit Card Number" << endl;
    cout << "*************************************************************************" << endl << endl << endl;

    string num;

    // This keeps on asking for inputs until 0 is entered
    while (true) {
        cout << "Please enter a Credit Card number to validate (enter 0 to exit): ";
        cin >> num;

        // To exit the execution
        if (num == "0") {
            cout << endl << "--------Thank You--------" << endl << endl;
            break;
        }

        // Checking for character validity
        if (!areAllnum(num)) {
            cout << endl << "************************You have entered a wrong Credit Card Number ************************" << endl << endl << endl;
            continue;
        }

        // Checking for size validity
        if (!sizeValidity(num)) {
            cout << endl << "************************You have entered a wrong Credit Card Number ************************" << endl << endl << endl;
            continue;
        }

        // Luhn's Algorithm implementation
        int len = num.length();
        int evenDigitSum = 0;
        int oddDigitSum = 0;

        // Step 1: Double every second digit from the right
        for (int i = len - 2; i >= 0; i -= 2) {
            int doubleofDig = (num[i] - '0') * 2;
            if (doubleofDig > 9)
                doubleofDig = (doubleofDig / 10) + (doubleofDig % 10);
            evenDigitSum += doubleofDig;
        }

        // Step 2: Sum every odd-placed digit from the right
        for (int i = len - 1; i >= 0; i -= 2) {
            oddDigitSum += (num[i] - '0');
        }

        // Step 3: Combine both sums
        int totalSum = oddDigitSum + evenDigitSum;

        // Step 4: Check if totalSum is a multiple of 10
        if (totalSum % 10 == 0) {
            cout << endl << "-------------------------------It is a Valid Credit Card Number------------------------" << endl << endl << endl;
        } else {
            cout << endl << "************************You have entered a wrong Credit Card Number ************************" << endl << endl << endl;
        }
    }

    return 0;
}
