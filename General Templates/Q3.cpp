#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minOps(int N, string& S1, string& S2, string& S3) {
    
    int total0 = 0, total1 = 0;
    for (int i = 0; i < N; i++) {
        total0 += (S1[i] == '0') + (S2[i] == '0') + (S3[i] == '0');
        total1 += (S1[i] == '1') + (S2[i] == '1') + (S3[i] == '1');
    }

    bool possibleAll0 = (total0 >= 3 * N);
    bool possibleAll1 = (total1 >= 3 * N);

    if (!possibleAll0 && !possibleAll1) {
        return -1; // Not possible
    }

    int operationsAll0 = 0;
    if (possibleAll0) {
        int count0_S1 = count(S1.begin(), S1.end(), '0');
        int count0_S2 = count(S2.begin(), S2.end(), '0');
        int count0_S3 = count(S3.begin(), S3.end(), '0');
        operationsAll0 = max(0, N - count0_S1) + max(0, N - count0_S2) + max(0, N - count0_S3);
    }

    int operationsAll1 = 0;
    if (possibleAll1) {
        int count1_S1 = count(S1.begin(), S1.end(), '1');
        int count1_S2 = count(S2.begin(), S2.end(), '1');
        int count1_S3 = count(S3.begin(), S3.end(), '1');
        operationsAll1 = max(0, N - count1_S1) + max(0, N - count1_S2) + max(0, N - count1_S3);
    }

    if (possibleAll0 && possibleAll1) {
        return min(operationsAll0, operationsAll1);
    } else if (possibleAll0) {
        return operationsAll0;
    } else {
        return operationsAll1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T; 

    while (T--) {
        int N;
        cin >> N; 
        string S1, S2, S3;
        cin >> S1 >> S2 >> S3; 

        cout << minOps(N, S1, S2, S3) << "\n";
    }

    return 0;
}