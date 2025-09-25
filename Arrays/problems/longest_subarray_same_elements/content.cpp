#include &lt;iostream&gt;
#include &lt;vector&gt;
using namespace std;

// Function declaration
int longestSubarraySameElement(const vector&lt;int&gt;&amp; arr){
    
    if(arr.size()==0)return 0;
        int maxLength=1;
    
    int l=0;

    for(int r=1;r&lt;arr.size();r++){
        
        if(arr[r] != arr[r-1]){
            l=r;
        }
        
        maxLength=max(maxLength,r-l+1);
        
    }
    return maxLength;
}