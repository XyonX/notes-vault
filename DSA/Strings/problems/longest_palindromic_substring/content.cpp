// Longest Palindromic Substring - Expand Around Center Approach
class Solution {
public:
    string longestPalindrome(string s) {
        string longest = "";
        int maxLength = 0;
        int n = s.size();
        int stringStart = 0;
        int stringEnd = 0;

        for(int i = 0; i < n; i++) {
            // For odd length
            int l = i;
            int r = i;
            while(l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }

            if(r - l - 1 > maxLength) {
                maxLength = r - l - 1;
                stringStart = l + 1;
                stringEnd = r - 1;
            }

            // For even length
            l = i;
            r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            if(r - l - 1 > maxLength) {
                maxLength = r - l - 1;
                stringStart = l + 1;
                stringEnd = r - 1;
            }
        }

        return s.substr(stringStart, maxLength);
    }
};