#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<vector<int> > events;

void init() {
    string line;
    getline(cin, line);
    istringstream ss(line);
    int num;
    int pos = 0;
    vector<int> temp (3, 0);
    while(ss >> num) {
        temp[pos%3] = num;
        if(pos % 3 == 0 && pos != 0) events.push_back(temp);
    }
}

int maxTwoEvents(vector<vector<int> >& events) {
    int n = events.size();
    
    sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    vector<int> suffixMax(n);
    suffixMax[n-1] = events[n-1][2];

    for (int i = n - 2; i < n; --i) {
        suffixMax[i] = max(events[i][2], suffixMax[i+1]);
    }

    int maxSum = 0;

    for (int i = 0; i < n; ++i) {
        int left = i + 1, right = n - 1;
        int nextEventIndex = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if(events[mid][0] > events[i][1]) {
                nextEventIndex = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if(nextEventIndex != -1) {
            maxSum = max(maxSum, events[i][2] + suffixMax[nextEventIndex]);
        }

        maxSum = max(maxSum, events[i][2]);
    }

    return maxSum;
}
            
int main() {
    init(); 

    cout << maxTwoEvents(events) << endl;

    return 1;
}

// 2054. Two Best Non-Overlapping Events 
// Daily question: 08/12/2024 - Medium