// 3rd of https://drive.google.com/drive/u/3/folders/1DF09TCciQNH-CT1Ra9MwTsgGKetZnUXh
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    unordered_map<int, int> frequency;
    int maxFrequency = 0, result = INT_MAX;

    // Read the array and calculate frequencies
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        int freq = ++frequency[num];

        // Update result if a new max frequency is found or if the same frequency but smaller number
        if (freq > maxFrequency || (freq == maxFrequency && num < result)) {
            maxFrequency = freq;
            result = num;
        }
    }

    cout << result << '\n';
    return 0;
}