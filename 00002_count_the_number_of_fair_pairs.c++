class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // i < j mean that just different number
        sort(nums.begin(), nums.end());
        long long res = 0;
        int n = nums.size();

        for (int i = 0; i < n - 1; ++i) {
            int min_num = lower - nums[i];
            int max_num = upper - nums[i];

            // Binary search
            auto start = lower_bound(nums.begin() + i + 1, nums.end(), min_num);
            auto end = upper_bound(nums.begin() + i + 1, nums.end(), max_num);
            res += (end - start);
        }

        return res;
    }
};

// 2563. Count the Number of Fair Pairs
// Daily question: 13/11/2024 - Medium