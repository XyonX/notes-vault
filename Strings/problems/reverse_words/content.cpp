#include &lt;bits/stdc++.h&gt;

using namespace std;

// Function to reverse words in a string
string reverseWords(string s) {
    
    //remove leading spaces
    int from=0;
    while(from &lt;s.size() &amp;&amp; s[from] ==' '){
        from++;
    }
    //remove training spaces
    int to=s.size()-1;
    while(to&gt;=0 &amp;&amp; s[to]==' '){
        to--;
    }
    s=s.substr(from,to-from+1);
    
    reverse(s.begin(),s.end());
    s+=" ";
    int starting =0;
    for(int i=1;i&lt;s.size();i++){
        if(s[i]==' '){
            reverse(s.begin()+starting, s.begin()+i);
            starting =i+1;
        }
    }
    
    s.pop_back();
    return s;
    
}