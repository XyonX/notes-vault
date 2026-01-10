q1--


//fixed version
// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


/*
Identify time periods when a system experiences high load based on a rolling average calculation. For each minute in the monitoring period, calculate the average load over the most recent window of minutes. If this average exceeds the specified threshold, include that minute in your results.
The function detectHighLoadWindows will take three inputs:
int loadsin]: system load at each minute i (O-based) int windowSize: size of the rolling window in minutes int threshold: average load threshold to compare
against

*/

vector<int> detectHighLoadWindows(vector<int>& loads, int windowSize, int threshold){
    
    vector<int>res;
    long long  sum=0;
    for(int i=0;i<windowSize;i++){
        sum+=loads[i];
    }
    
    if( sum>1LL*threshold*windowSize){
        res.push_back(windowSize-1);
    }
    
    for(int i=windowSize;i<loads.size();i++){
        sum-=loads[i-windowSize];
        sum+=loads[i];
        
        if(sum> 1LL*threshold*windowSize){
            res.push_back(i);
        }
    }
    
    return res;
}




int main() {
    // Test 1: Simple case
    vector<int> loads1 = {1, 2, 3, 4, 5};
    int windowSize1 = 3;
    int threshold1 = 3;
    auto res1 = detectHighLoadWindows(loads1, windowSize1, threshold1);
    cout << "Test 1 result: ";
    for (int x : res1) cout << x << " ";
    cout << " | Expected: 4" << endl;

    // Test 2: All values equal
    vector<int> loads2 = {5, 5, 5, 5, 5};
    int windowSize2 = 2;
    int threshold2 = 5;
    auto res2 = detectHighLoadWindows(loads2, windowSize2, threshold2);
    cout << "Test 2 result: ";
    for (int x : res2) cout << x << " ";
    cout << " | Expected:" << endl;

    // Test 3: Window size = 1
    vector<int> loads3 = {1, 10, 2, 9};
    int windowSize3 = 1;
    int threshold3 = 5;
    auto res3 = detectHighLoadWindows(loads3, windowSize3, threshold3);
    cout << "Test 3 result: ";
    for (int x : res3) cout << x << " ";
    cout << " | Expected: 1 3" << endl;

    // Test 4: Low threshold
    vector<int> loads4 = {2, 3, 4};
    int windowSize4 = 2;
    int threshold4 = 1;
    auto res4 = detectHighLoadWindows(loads4, windowSize4, threshold4);
    cout << "Test 4 result: ";
    for (int x : res4) cout << x << " ";
    cout << " | Expected: 1 2" << endl;

    // Test 5: High threshold
    vector<int> loads5 = {10, 20, 30};
    int windowSize5 = 2;
    int threshold5 = 50;
    auto res5 = detectHighLoadWindows(loads5, windowSize5, threshold5);
    cout << "Test 5 result: ";
    for (int x : res5) cout << x << " ";
    cout << " | Expected:" << endl;

    // Test 6: Negatives + positives
    vector<int> loads6 = {-5, -2, 10, 5, -1};
    int windowSize6 = 3;
    int threshold6 = 2;
    auto res6 = detectHighLoadWindows(loads6, windowSize6, threshold6);
    cout << "Test 6 result: ";
    for (int x : res6) cout << x << " ";
    cout << " | Expected: 3 4" << endl;

    // Test 7: Window size = array size
    vector<int> loads7 = {4, 6, 8, 10};
    int windowSize7 = 4;
    int threshold7 = 6;
    auto res7 = detectHighLoadWindows(loads7, windowSize7, threshold7);
    cout << "Test 7 result: ";
    for (int x : res7) cout << x << " ";
    cout << " | Expected: 3" << endl;

    return 0;
}



#include <bits/stdc++.h>
using namespace std;

/*
Identify time periods when a system experiences high load based on a rolling average calculation. For each minute in the monitoring period, calculate the average load over the most recent window of minutes. If this average exceeds the specified threshold, include that minute in your results.
The function detectHighLoadWindows will take three inputs:
int loadsin]: system load at each minute i (O-based) int windowSize: size of the rolling window in minutes int threshold: average load threshold to compare
against


*/

vector<int> detectHighLoadWindows(vector<int>& loads, int windowSize, int threshold){
    
if (loads.size() < windowSize) return {};

    // vector<int>res(loads.size()-windowSize+1);
    vector<int>res;
    
    long long  windowSum=0;
    for(int i=0;i<windowSize;i++){
        windowSum+=loads[i];
    }
    
    //this works as if we multiply two value in. int it will pridcut int res so multple wiht a explicit long long 
    //THIS EXPRESSION WILL ALSO WORK
    //  if(windowSum>1LL * threshold * windowSize)
    long long anyVal=1;
    if(windowSum>= anyVal * threshold * windowSize)
    res.push_back(0);
    
    for(int i=1; i<=loads.size()-windowSize;i++){
        windowSum-=loads[i-1];
        windowSum+=loads[i+windowSize-1];
        if(windowSum>= 1LL * threshold * windowSize){
            res.push_back(i);
        }
    }
    
    return res;
    
    
}






int main() {
    // Test Case 1: Basic case
    vector<int> loads1 = {1, 2, 3, 4, 5};
    int windowSize1 = 3, threshold1 = 3;
    vector<int> result1 = detectHighLoadWindows(loads1, windowSize1, threshold1);
    cout << "Test Case 1: ";
    for (int idx : result1) cout << idx << " ";
    cout << endl;

    // Test Case 2: All windows exceed threshold
    vector<int> loads2 = {10, 12, 14, 16, 18};
    int windowSize2 = 2, threshold2 = 5;
    vector<int> result2 = detectHighLoadWindows(loads2, windowSize2, threshold2);
    cout << "Test Case 2: ";
    for (int idx : result2) cout << idx << " ";
    cout << endl;

    // Test Case 3: No windows exceed threshold
    vector<int> loads3 = {1, 1, 1, 1, 1};
    int windowSize3 = 3, threshold3 = 10;
    vector<int> result3 = detectHighLoadWindows(loads3, windowSize3, threshold3);
    cout << "Test Case 3: ";
    for (int idx : result3) cout << idx << " ";
    cout << endl;

    // Test Case 4: Window size equals array size
    vector<int> loads4 = {2, 4, 6, 8};
    int windowSize4 = 4, threshold4 = 5;
    vector<int> result4 = detectHighLoadWindows(loads4, windowSize4, threshold4);
    cout << "Test Case 4: ";
    for (int idx : result4) cout << idx << " ";
    cout << endl;

    // Test Case 5: Window size larger than array size (edge case)
    vector<int> loads5 = {3, 5};
    int windowSize5 = 5, threshold5 = 4;
    vector<int> result5 = detectHighLoadWindows(loads5, windowSize5, threshold5);
    cout << "Test Case 5: ";
    for (int idx : result5) cout << idx << " ";
    cout << endl;

    // Test Case 6: Mixed values with threshold at border
    vector<int> loads6 = {2, 2, 5, 5, 2, 2};
    int windowSize6 = 3, threshold6 = 3;
    vector<int> result6 = detectHighLoadWindows(loads6, windowSize6, threshold6);
    cout << "Test Case 6: ";
    for (int idx : result6) cout << idx << " ";
    cout << endl;

    // Test Case 7: Negative numbers
    vector<int> loads7 = {-5, -2, -3, -4, -1};
    int windowSize7 = 2, threshold7 = -3;
    vector<int> result7 = detectHighLoadWindows(loads7, windowSize7, threshold7);
    cout << "Test Case 7: ";
    for (int idx : result7) cout << idx << " ";
    cout << endl;

    // Test Case 8: Threshold equals exact window sum
    vector<int> loads8 = {2, 2, 2, 2};
    int windowSize8 = 2, threshold8 = 4;
    vector<int> result8 = detectHighLoadWindows(loads8, windowSize8, threshold8);
    cout << "Test Case 8: ";
    for (int idx : result8) cout << idx << " ";
    cout << endl;

    // Test Case 9: Window size = 1
    vector<int> loads9 = {1, 5, 3, 7};
    int windowSize9 = 1, threshold9 = 4;
    vector<int> result9 = detectHighLoadWindows(loads9, windowSize9, threshold9);
    cout << "Test Case 9: ";
    for (int idx : result9) cout << idx << " ";
    cout << endl;

    // Test Case 10: Window size = 0 (invalid)
    vector<int> loads10 = {1, 2, 3};
    int windowSize10 = 0, threshold10 = 1;
    vector<int> result10 = detectHighLoadWindows(loads10, windowSize10, threshold10);
    cout << "Test Case 10: ";
    for (int idx : result10) cout << idx << " ";
    cout << endl;

    // Test Case 11: Large values (overflow risk)
    vector<int> loads11 = {1000000000, 1000000000, 1000000000};
    int windowSize11 = 2, threshold11 = 1500000000;
    vector<int> result11 = detectHighLoadWindows(loads11, windowSize11, threshold11);
    cout << "Test Case 11: ";
    for (int idx : result11) cout << idx << " ";
    cout << endl;

    // Test Case 12: Alternating highs and lows
    vector<int> loads12 = {10, 0, 10, 0, 10};
    int windowSize12 = 2, threshold12 = 10;
    vector<int> result12 = detectHighLoadWindows(loads12, windowSize12, threshold12);
    cout << "Test Case 12: ";
    for (int idx : result12) cout << idx << " ";
    cout << endl;

    return 0;
}





q2--

optimized one 
// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


/*

The problem statement, based on the provided image and context, is as follows:

The stock performance of a company is being examined to assess its net profit over time.
For a given analysis parameter ( k ), an interval of ( k ) consecutive months is considered highly profitable if the stock prices increase strictly throughout those months. Given the stock prices for ( n ) months and the analysis parameter ( k ), determine the number of such highly profitable intervals.
*/



int countHighlyProfitableMonths(vector <int>stockPrices, int k) {
    int n=stockPrices.size();
    int count =0;
    //build increament array 
    vector<int>inc;
    
    for(int i=0;i<n-1;i++){
        if(stockPrices[i+1]> stockPrices[i]){
            inc.push_back(1);
        }else{
            inc.push_back(-1);
        }
    }
    
    int sum=0;
    //now first slide over the inc array
    int windowSize=k-1;
    for(int i=0;i<windowSize;i++){
        sum+=inc[i];
    }
    if(sum==windowSize)count++;
    
    for(int i=windowSize;i<n-1;i++){
        sum-=inc[i-windowSize];
        sum+=inc[i];
        if(sum==windowSize)count++;
    }
    return count;
    
}


int main() {
    // Test 1: Simple increasing sequence
    {
        vector<int> stockPrices = {1, 2, 3, 4, 5};
        int k = 3;
        cout << "Test 1 Expected: 3, Got: "
             << countHighlyProfitableMonths(stockPrices, k) << endl;
        // Explanation: [1,2,3], [2,3,4], [3,4,5]
    }

    // Test 2: No increasing sequence
    {
        vector<int> stockPrices = {5, 5, 5, 5};
        int k = 2;
        cout << "Test 2 Expected: 0, Got: "
             << countHighlyProfitableMonths(stockPrices, k) << endl;
        // Explanation: Prices never strictly increase
    }

    // Test 3: k = 1 (edge case)
    {
        vector<int> stockPrices = {2, 4, 6};
        int k = 1;
        cout << "Test 3 Expected: 3, Got: "
             << countHighlyProfitableMonths(stockPrices, k) << endl;
        // Explanation: Every single month counts as increasing
    }

    // Test 4: Mixed increases and decreases
    {
        vector<int> stockPrices = {1, 2, 1, 2, 3};
        int k = 2;
        cout << "Test 4 Expected: 3, Got: "
             << countHighlyProfitableMonths(stockPrices, k) << endl;
        // Explanation: [1,2] (index 0-1), [1,2] (index 2-3), [2,3] (index 3-4)
    }

    // Test 5: Large k value (equals array size)
    {
        vector<int> stockPrices = {1, 3, 5, 7};
        int k = 4;
        cout << "Test 5 Expected: 1, Got: "
             << countHighlyProfitableMonths(stockPrices, k) << endl;
        // Explanation: Whole array is strictly increasing
    }

    // Test 6: Hard case - alternating up and down
    {
        vector<int> stockPrices = {1, 3, 2, 4, 3, 5, 4, 6};
        int k = 3;
        cout << "Test 6 Expected: 0, Got: "
             << countHighlyProfitableMonths(stockPrices, k) << endl;
        // Explanation: No 3-length strictly increasing subsequence
    }

    // Test 7: Long strictly increasing array
    {
        vector<int> stockPrices = {1,2,3,4,5,6,7,8,9,10};
        int k = 5;
        cout << "Test 7 Expected: 6, Got: "
             << countHighlyProfitableMonths(stockPrices, k) << endl;
        // Explanation: Windows: [1,2,3,4,5] up to [6,7,8,9,10]
    }

    return 0;
}


// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


/*

The problem statement, based on the provided image and context, is as follows:

The stock performance of a company is being examined to assess its net profit over time.
For a given analysis parameter ( k ), an interval of ( k ) consecutive months is considered highly profitable if the stock prices increase strictly throughout those months. Given the stock prices for ( n ) months and the analysis parameter ( k ), determine the number of such highly profitable intervals.
*/



int countHighlyProfitableMonths(vector <int>stockPrices, int k) {
    
    int size=stockPrices.size();
    int count=0;

    for(int i=0;i<=size-k;i++){
        bool flag = true;
        for(int j=i;j<i+k-1;j++){
            if(stockPrices[j] >= stockPrices[j+1]){
                flag=false;
                break;
            }
        }
        if(flag)
        count++;
    }
    
    return count;
}






int main() {
    // Test 1: Example case
    vector<int> prices1 = {1, 5, 3, 5, 7, 8};
    int k1 = 3;
    cout << "Test 1 Output = " << countHighlyProfitableMonths(prices1, k1) 
         << " | Expected = 2" << endl;

    // Test 2: Fully increasing sequence
    vector<int> prices2 = {1, 2, 3, 4, 5};
    int k2 = 2;
    cout << "Test 2 Output = " << countHighlyProfitableMonths(prices2, k2) 
         << " | Expected = 4" << endl;

    // Test 3: Fully decreasing sequence
    vector<int> prices3 = {5, 4, 3, 2, 1};
    int k3 = 3;
    cout << "Test 3 Output = " << countHighlyProfitableMonths(prices3, k3) 
         << " | Expected = 0" << endl;

    // Test 4: Mixed with plateaus
    vector<int> prices4 = {2, 2, 3, 4, 5};
    int k4 = 3;
    cout << "Test 4 Output = " << countHighlyProfitableMonths(prices4, k4) 
         << " | Expected = 2" << endl;

    // Test 5: Smallest k (k = 1)
    vector<int> prices5 = {10, 20, 30};
    int k5 = 1;
    cout << "Test 5 Output = " << countHighlyProfitableMonths(prices5, k5) 
         << " | Expected = 3" << endl;

    // Test 6: k equal to n
    vector<int> prices6 = {1, 2, 3, 4};
    int k6 = 4;
    cout << "Test 6 Output = " << countHighlyProfitableMonths(prices6, k6) 
         << " | Expected = 1" << endl;

    // Test 7: Random zig-zag sequence
    vector<int> prices7 = {1, 3, 2, 4, 6, 5, 7};
    int k7 = 3;
    cout << "Test 7 Output = " << countHighlyProfitableMonths(prices7, k7) 
         << " | Expected = 1" << endl;

    return 0;
}


