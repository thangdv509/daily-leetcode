#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
#include<unordered_set>
#include<utility>
using namespace std;

vector<vector<int> > points;

void init() {
    string line;
    getline(cin, line);
    istringstream ss(line);
    int pos = 0;
    int num;
    vector<int> temp(2, 0);
    while(ss >> num) {
        temp[pos] = num;
        if(pos % 2 == 1) points.push_back(temp);
        pos ++;  
    }
}

string pointToString(int x, int y) {
    return to_string(x) + "," + to_string(y);
}

bool isRectangleValid(int xMin, int xMax, int yMin, int yMax, const unordered_set<string>& pointSet, const vector<pair<int, int> >& corners) {
    for(int x = xMin; x < xMax; ++x) {
        for (int y = yMin; y < yMax; ++y) {
            string point = pointToString(x, y);
            if(find(corners.begin(), corners.end(), make_pair(x, y)) != corners.end()) continue; 
            if(pointSet.count(point)) return false; 
        }
    }

    return true;
}

int maxRectangleArea(vector<vector<int> >& points) {
    unordered_set<string> pointSet;

    for (const auto& p : points) pointSet.insert(pointToString(p[0], p[1]));

    int maxArea = -1; 

    for(int i = 0; i < points.size(); ++i) {
        for(int j = i + 1; j < points.size(); ++j) {
            int x1 = points[i][0], y1 = points[i][1];
            int x2 = points[j][0], y2 = points[j][1];

            if(x1 != x2 && y1 != y2) {
                pair<int, int> p3 = {x1, y2};
                pair<int, int> p4 = {x2, y1};

                if(pointSet.count(pointToString(p3.first, p3.second)) && pointSet.count(pointToString(p4.first, p4.second))) {
                    int xMin = min(x1, x2), xMax = max(x1, x2);
                    int yMin = min(y1, y2), yMax = max(y1, y2);

                    vector<pair<int, int> > corners = {{x1, y1}, {x2, y2}, {p3.first, p3.second}, {p4.first, p4.second}};
                    if(isRectangleValid(xMin, xMax, yMin, yMax, pointSet, corners)) {
                        int area = abs(x2 - x1) * abs(y2 - y1);
                        maxArea = max(maxArea, area); 
                    }
                }
            }
        }
    }
    return maxArea;
}
                
int main () {
    init();

    cout << maxRectangleArea(points) << endl; 

    return 1; 
}

// 3380. Maximum Area Rectangle With Point Constraints I
// Weekly Contest 427: 08/12/2024 - Medium