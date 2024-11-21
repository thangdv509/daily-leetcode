class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = 0;
        int n = candies.size();
        vector<bool> res(n, false);

        for(int i = 0; i < n; ++i) maxCandies = max(maxCandies, candies[i]);
        for(int i = 0; i < n; ++i) {
            if(candies[i] + extraCandies >= maxCandies) res[i] = true;
        }

        return res;
    }
};

// 1431. Kids With the Greatest Number of Candies
// Leetcode 75: 21/11/2024 - Easy