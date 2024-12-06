#include<iostream>
#include<vector>
#include<unordered_set>
#include<sstream>
using namespace std;

vector<int> banned;
int n, maxSum;

void init() {
    string line;
    getline(cin, line);
    istringstream ss(line);
    int num;
    while(ss >> num) {
        banned.push_back(num);
    }

    cin >> n >> maxSum;

}

int maxCount(vector<int>& banned, int n, int maxSum) {
    unordered_set<int> bannedSet(banned.begin(), banned.end());

    long long sum = 0;
    int count = 0;

    for(int i = 1; i <= n; ++i) {
        if(bannedSet.count(i)) continue;
        sum += i;
        if(sum > maxSum) break;
        count ++;
    }

    return count;
}

int main() {
    init();
    cout << maxCount(banned, n, maxSum) << endl;

    return 1;
}

// 2554. Maximum Number of Integers to Choose From a Range I
// Daily question: 06/12/2024 - Medium