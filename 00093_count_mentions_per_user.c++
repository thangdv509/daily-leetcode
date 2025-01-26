#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<vector<string>> events;
int numberOfUsers;

void init() {
    string line;
    while(getline(cin, line)) {
        if(line.empty()) break;
        istringstream ss (line);
        vector<string> event;
        string s;
        while(ss >> s) event.push_back(s);
        events.push_back(event);
    }

    cin >> numberOfUsers;
}

vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
    vector<int> available(numberOfUsers, -1);
    vector<int> res(numberOfUsers, 0);

    sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
        int numA = stoi(a[1]);
        int numB = stoi(b[1]);
    
        if (numA != numB) {
            return numA < numB;
        }
    
        return a[0] > b[0];
    });

    for(auto& event : events){
        cout << event[0] << " " << event[1] << " " << event[2] << endl;
        if(event[0] == "OFFLINE") {
            available[stoi(event[2])] = stoi(event[1]) + 60;
        }
        else {
            if(event[2] == "ALL") {
                for(int i = 0; i < numberOfUsers; ++i) res[i] += 1;
            } else if(event[2] == "HERE") {
                for(int i = 0; i < numberOfUsers; ++i) {
                    if(stoi(event[1]) >= available[i]) res[i] += 1;
                }
            }
            else {
                vector<int> users;
                istringstream ss (event[2]);
                string s;
                while(ss >> s) {
                    int userId = stoi(s.substr(2));
                    users.push_back(userId);
                }

                for(int id : users) {
                    res[id] += 1;
                }
            }
        }
    }
    
    return res;
}

int main() {
    init();

    vector<int> res = countMentions(numberOfUsers, events);

    for(int num : res) cout << num << " ";
    cout << endl;

    return 0;
}

// 3433. Count Mentions Per User
// Weekly Contest 434: 26/01/2025 - Medium