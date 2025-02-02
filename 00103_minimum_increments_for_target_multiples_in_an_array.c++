#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

vector<int> numbers;
vector<int> goals;


void init() {
    string line;
    getline(cin, line);
    istringstream ss (line);
    int number;
    while(ss >> number) numbers.push_back(number);

    getline(cin, line);
    istringstream ss (line);
    int goal;
    while(ss >> goal) goals.push_back(goal);
}

long long calculate_gcd(long long x, long long y) {
    while (y) {
        long long temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}
    
long long calculate_lcm(long long x, long long y) {
    return x / calculate_gcd(x, y) * y;
}
    
long long find_lcm_of_list(const vector<int>& values) {
    if (values.empty()) {
        return 1;
    }
    
    long long current_lcm = values[0];
    
    for (size_t i = 1; i < values.size(); ++i) {
        current_lcm = calculate_lcm(current_lcm, values[i]);
    }
    return current_lcm;
}
    
long long minimumIncrements(const vector<int>& numbers, const vector<int>& goal) {
    int size = goal.size();
    int total_subsets = 1 << size;
    vector<pair<int, long long>> subset_details;
    
    for (int bitmask = 0; bitmask < total_subsets; ++bitmask) {
        vector<int> selected_elements;
        for (int i = 0; i < size; ++i) {
            if (bitmask & (1 << i)) {
                selected_elements.push_back(goal[i]);
            }
        }
            
        long long current_lcm = find_lcm_of_list(selected_elements);
        subset_details.push_back({bitmask, current_lcm});
    }
    
    int complete_mask = (1 << size) - 1;
    int dp_length = 1 << size;
    vector<long long> dp_table(dp_length, LLONG_MAX);
    dp_table[0] = 0;
    
    for (int num : numbers) {
        vector<long long> temp_dp = dp_table;
    
        for (const auto& subset : subset_details) {
            int subset_bitmask = subset.first;
            long long subset_lcm = subset.second;

            long long increment = 0;
            if (subset_bitmask != 0) {
                if (num % subset_lcm != 0) {
                    increment = ((num / subset_lcm) + 1) * subset_lcm - num;
                }
            }
    
            for (int bitmask = 0; bitmask < dp_length; ++bitmask) {
                if (dp_table[bitmask] == LLONG_MAX) {
                    continue;
                }
    
                int new_bitmask = bitmask | subset_bitmask;
                long long new_cost = dp_table[bitmask] + increment;
    
                if (new_cost < temp_dp[new_bitmask]) {
                    temp_dp[new_bitmask] = new_cost;
                }
            }
        }
        dp_table = temp_dp;
    }
    
    return dp_table[complete_mask] != LLONG_MAX ? dp_table[complete_mask] : 0;
}

int main() {
    init();

    cout << minimumIncrements(numbers, goals) << endl;

    return 0;
}

// 3444. Minimum Increments for Target Multiples in an Array
// Weekly Contest 435: 01/02/2025 - Hard