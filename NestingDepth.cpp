// codejamQualif.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main2()
{
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; t++) {
        string S;
        cin >> S;
        string result = "";
        //build
        for (char c : S) {
            int n = c - '0';
            for (int i = 0; i < n; i++) {
                result += "(";
            }
            result += c;
            for (int i = 0; i < n; i++) {
                result += ")";
            }
        }

        //reduce
        for (int i = 0; i < result.size() - 1; i++) {
            if (result[i] == ')' && result[i + 1] == '(') {
                result = result.substr(0, i) + result.substr(i + 2);
                i = i - 2;
            }
        }

        cout << "Case #" + to_string(t) + ": " << result << endl;
    }
    return 0;
}
