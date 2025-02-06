#include <vector>
#include <unordered_map>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> nums;

void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    int num;
    while(ss >> num) nums.push_back(num);
}

int tupleSameProduct(vector<int>& nums) {
    unordered_map<int, int> mp;
    int ans = 0, n = nums.size();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int product = nums[i] * nums[j];
            ans += 8 * mp[product];
            mp[product]++;
        }
    return ans;
}

int main() {
    init();

    cout << tupleSameProduct(nums) << endl;

    return 0;
}

// 1726. Tuple with Same Product
// Daily question: 06/02/2025 - Medium