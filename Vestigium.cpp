// codejamQualif.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void main1()
{
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; t++) {
        int N;
        cin >> N;
        int* rowDuplicates = new int[N];
        int* colDuplicates = new int[N];

        for (int i = 0; i < N; i++) {
            rowDuplicates[i] = -1;
            colDuplicates[i] = -1;
        }

        vector<vector<int>> arr;
        int nbRowDuplicates = 0;
        int nbColDuplicates = 0;

        bool isRowDuplicate = false;

        int trace = 0;
        for (int j = 0; j < N; j++) {
            isRowDuplicate = false;
            vector<int> v;
            for (int i = 0; i < N; i++) {
                int nb;
                cin >> nb;
                if (i == j) trace += nb;
                v.push_back(nb);

                if (!isRowDuplicate && rowDuplicates[nb - 1] == j) {
                    isRowDuplicate = true;
                    nbRowDuplicates++;
                }
                rowDuplicates[nb - 1] = j;
            }
            arr.push_back(v);
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                int nb = arr[j][i];

                if (colDuplicates[nb - 1] == i) {
                    nbColDuplicates++;
                    break;
                }
                colDuplicates[nb - 1] = i;
            }

        cout << "Case #" + to_string(t) + ": " << to_string(trace) << " " << to_string(nbRowDuplicates) << " " << to_string(nbColDuplicates) << endl;
    }
}
