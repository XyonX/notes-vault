class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if (s.empty())return 0;

        vector<int> freq(256, -1);  
        int maxLength=0;
        int l=0;

        for(int r=0;r<s.size();r++){

            // char c=s[r];
            unsigned char c = s[r];  

            if(freq[c] !=-1 &&  freq[c]>=l){
                l=freq[c]+1;
            }

            maxLength=max(maxLength,r-l+1);
            freq[c]=r;
        }
        return maxLength;
        
    }
};