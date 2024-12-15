#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
#include<utility>
using namespace std;

vector<vector<int> >& classes;
int extraStudents;

void init() {
    string line;
    getline(cin, line);
    istringstream ss(line);
    int num;
    int pos = 0;
    vector<int> temp (2, 0);
    while (ss >> num) {
        temp[pos%2] = num;
        if (pos%2 == 1) classes.push_back(temp);
    }

    cin >> extraStudents;
}
 
double maxAverageRatio(vector<vector<int> >& classes, int extraStudents) {
    auto gain = [](double pass, double total) {
        return (pass + 1) / (total + 1) - pass / total;
    };

    priority_queue<pair<double, pair<int, int> > > maxHeap;

    double sum = 0.0;

    for (const auto& cls : classes) {
        int pass = cls[0];
        int total = cls[1];
        sum += (double) pass / total;
        maxHeap.push({gain(pass, total), {pass, total}});
    }

    for (int i = 0; i < extraStudents; ++i) {
        auto[currentGain, data] = maxHeap.top(); 
        maxHeap.pop();

        int pass = data.first;
        int total = data.second;

        sum -= (double) pass / total;
        pass += 1;
        total += 1;
        sum += (double) pass / total;

        maxHeap.push({gain(pass, total), {pass, total}});
    }

    return sum / classes.size();
}


int main () {
    int();

    cout << maxAverageRatio(classes, extraStudents) << endl;

    return 0;
}

// 1792. Maximum Average Pass Ratio
// Daily question: 15/12/2024 - Medium