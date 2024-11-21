class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        if(word1=="")
        {
            return word2;
        }
        else if(word2=="")
        {
            return word1;
        }

        int l1 = word1.size()-1;
        int l2 = word2.size()-1;

        string s;

        while(l1>=0 ||l2>=0)
        {
            if(l1>=0 && l2>=0)
            {
                s=s+word1[word1.size()-1-l1];
                s=s+word2[word2.size()-1-l2];
            }

            else if(l1>=0 && l2<0)
            {
                s=s+word1[word1.size()-1-l1];
            }
            else if (l1<0 && l2>=0)
            {
                s=s+word2[word2.size()-1-l2];
            }

            l1--;
            l2--;
        }

        return s;
        
    }
};

// 1768. Merge Strings Alternately
// Leetcode 75: 21/11/2024 - Easy