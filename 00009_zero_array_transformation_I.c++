class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        if(nums.size() == 1) {
            if(nums[0] == 0) return 2;
            else return 0;
        }
        
        int curSumLeft = 0;
        int curSumRight = 0;
        int res = 0;

        for(int i = 1; i < nums.size(); ++i){
            curSumRight += nums[i];
        }

        for(int i = 0; i < nums.size() - 1; ++i){
            if(nums[i] == 0) {
                 if(curSumLeft == curSumRight) res += 2;
                else if(abs(curSumLeft - curSumRight) == 1) res += 1;   
            }
            
            curSumLeft += nums[i];
            curSumRight -= nums[i+1];
        }

        if(curSumLeft == curSumRight && nums[nums.size() - 1] == 0) res += 2;
        else if(curSumLeft == 1 && nums[nums.size() - 1] == 0) res += 1;
        return res; 
    }
};

// 3354. Make Array Elements Equal to Zero
// Weekly Contest 424: 16/11/2024 - Easy