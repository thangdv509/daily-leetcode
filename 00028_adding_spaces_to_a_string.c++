class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        int curSpaceIndex = 0;
        for (int i = 0; i < s.size(); ++i) {
            if(i == spaces[curSpaceIndex]) {
                res += " ";
                if(curSpaceIndex < spaces.size() - 1) curSpaceIndex ++;
            };
            res += s[i];
        }
        return res;
    }
};

// 2109. Adding Spaces to a String
// Daily question: 03/12/2024 - Medium