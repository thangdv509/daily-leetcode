#include<iostream>
#include<unordered_set>
using namespace std;

#define MAX 500
vector<int> arr(500, 0);
unordered_set<int> check;
int n;

void init() {
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
}

bool checkIfExist(vector<int>& arr) {
    for(int num : arr) {
        if(check.count(num*2) || (num % 2 == 0 && check.count(num/2))) return true;
        check.insert(num);
    }
}

int main() {
    init();
    checkIfExist(arr);
    return 0;
}

// 1346. Check If N and Its Double Exist
// Daily question: 01/12/2024 - Easy 