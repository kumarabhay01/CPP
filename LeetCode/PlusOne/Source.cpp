#include<iostream>
#include<vector>

using namespace std;


vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();

    // Start from the rightmost digit
    for (int i = n - 1; i >= 0; --i) {
        // If the current digit is not 9, simply increment it by 1 and return
        if (digits[i] != 9) {
            digits[i]++;
            return digits;
        }
        // If the current digit is 9, set it to 0 and continue to the next digit
        digits[i] = 0;
    }

    // If all digits were 9, we need to add an additional digit at the beginning
    digits.insert(digits.begin(), 1);

    return digits;
}

vector<int> plusOne_2(vector<int>& digits) {
    int index = digits.size() - 1;
    while (index >= 0 && digits[index] == 9)
        digits[index--] = 0;

    if (index < 0)
        digits.insert(digits.begin(), 1);
    else
        digits[index]++;

    return digits;
}

int main() {
    vector<int> digits{ 1,2,3 };
    for (int digit : digits)
        cout << digit;
    cout << endl;
    digits =  plusOne(digits);
    for (int digit : digits)
        cout << digit;
    return 0;
}
