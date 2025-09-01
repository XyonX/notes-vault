#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> arr){
    vector<int> res(arr.size());
    
    stack<int> st;
    st.push(-1);
   
    for(int i = arr.size() - 1; i >= 0; i--){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        
        if(st.empty()){
            res[i] = -1;
        } else {
            res[i] = st.top();
        }
        
        st.push(arr[i]);
    }
    return res;
}

int main() {
    // Test case 1
    vector<int> arr1 = {4, 5, 2, 25};
    vector<int> res1 = nextGreaterElement(arr1);
    cout << "Test 1: ";
    for (int x : res1) cout << x << " ";
    cout << endl;

    // Test case 2
    vector<int> arr2 = {13, 7, 6, 12};
    vector<int> res2 = nextGreaterElement(arr2);
    cout << "Test 2: ";
    for (int x : res2) cout << x << " ";
    cout << endl;

    // Test case 3
    vector<int> arr3 = {3, 1, 4, 2};
    vector<int> res3 = nextGreaterElement(arr3);
    cout << "Test 3: ";
    for (int x : res3) cout << x << " ";
    cout << endl;

    // Test case 4 (all decreasing)
    vector<int> arr4 = {9, 7, 5, 3, 1};
    vector<int> res4 = nextGreaterElement(arr4);
    cout << "Test 4: ";
    for (int x : res4) cout << x << " ";
    cout << endl;

    // Test case 5 (all equal)
    vector<int> arr5 = {2, 2, 2, 2};
    vector<int> res5 = nextGreaterElement(arr5);
    cout << "Test 5: ";
    for (int x : res5) cout << x << " ";
    cout << endl;

    return 0;
}