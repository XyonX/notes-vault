LEETCODE - 643-MAX AVERAGE SUBARRAY

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {


        int windowSum=0;
        for(int i=0;i<k;i++){
            windowSum+=nums[i];
        }
        double maxAvg = double(windowSum)/k;


        for(int i=1;i<=nums.size()-k;i++){
            windowSum-=nums[i-1];
            windowSum+=nums[i+k-1];
            
            double avg=double(windowSum)/k;
            maxAvg=max(avg,maxAvg);
        }

        return maxAvg;
        
    }
};


LEETCODE- 1343

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int count=0;

        double sum=0;

        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        int avg =  sum/k;
        if(avg>=threshold) count++;

        for(int i=1;i<=arr.size()-k;i++){
            sum-=arr[i-1];
            sum+=arr[i+k-1];
            avg = sum/k;
            if(avg>=threshold)count++;

        }
        return count;
    }
};



//TWO POINTER PROBLEMS

//leetcode 11 - CONTIANER WITH MOST WATER

#include <bits/stdc++.h>
using namespace std;

// Function template for Container With Most Water
int maxArea(vector<int>& height) {

    int l=0;
    int r=height.size()-1;
    
    int maxArea=INT_MIN;
    while(l<r){
        int area = min(height[l],height[r])*(r-l);
        maxArea=max(area,maxArea);
        
        if(height[l]<height[r])l++;
        else r--;
    }
    return maxArea;
}

int main() {
    // Test Case 1: Basic case
    vector<int> heights1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Test Case 1 Output: " << maxArea(heights1) << endl;
    // Expected: 49

    // Test Case 2: Small input
    vector<int> heights2 = {1, 1};
    cout << "Test Case 2 Output: " << maxArea(heights2) << endl;
    // Expected: 1

    // Test Case 3: Increasing heights
    vector<int> heights3 = {1, 2, 3, 4, 5};
    cout << "Test Case 3 Output: " << maxArea(heights3) << endl;
    // Expected: 6

    // Test Case 4: Decreasing heights
    vector<int> heights4 = {5, 4, 3, 2, 1};
    cout << "Test Case 4 Output: " << maxArea(heights4) << endl;
    // Expected: 6

    // Test Case 5: All same height
    vector<int> heights5 = {5, 5, 5, 5, 5};
    cout << "Test Case 5 Output: " << maxArea(heights5) << endl;
    // Expected: 20

    return 0;
}


//three sum brtue 
#include <bits/stdc++.h>
using namespace std;

// Function template for 3Sum
vector<vector<int>> threeSum(vector<int>& nums) {

    set<vector<int>>res;
    
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int>triplet={nums[i],nums[j],nums[k]};
                    sort(triplet.begin(), triplet.end());
                    res.insert(triplet);
                }
            }
        }
    }
    vector<vector<int>> v(res.begin(), res.end());
    return v;
}

int main() {
    // Test Case 1: Standard case
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    auto result1 = threeSum(nums1);
    cout << "Test Case 1 Output: ";
    for (auto &triplet : result1) {
        cout << "[";
        for (int x : triplet) cout << x << " ";
        cout << "] ";
    }
    cout << endl;
    // Expected: [-1,-1,2] [-1,0,1]

    // Test Case 2: No triplets
    vector<int> nums2 = {0, 1, 1};
    auto result2 = threeSum(nums2);
    cout << "Test Case 2 Output: ";
    for (auto &triplet : result2) {
        cout << "[";
        for (int x : triplet) cout << x << " ";
        cout << "] ";
    }
    cout << endl;
    // Expected: []

    // Test Case 3: All zeros
    vector<int> nums3 = {0, 0, 0};
    auto result3 = threeSum(nums3);
    cout << "Test Case 3 Output: ";
    for (auto &triplet : result3) {
        cout << "[";
        for (int x : triplet) cout << x << " ";
        cout << "] ";
    }
    cout << endl;
    // Expected: [0,0,0]

    // Test Case 4: Larger input
    vector<int> nums4 = {-2, 0, 1, 1, 2};
    auto result4 = threeSum(nums4);
    cout << "Test Case 4 Output: ";
    for (auto &triplet : result4) {
        cout << "[";
        for (int x : triplet) cout << x << " ";
        cout << "] ";
    }
    cout << endl;
    // Expected: [-2,0,2] [-2,1,1]

    return 0;
}


//three sum two pointer 
#include <bits/stdc++.h>
using namespace std;

// Function template for 3Sum
// vector<vector<int>> threeSum(vector<int>& nums) {

//     set<vector<int>>res;
    
//     int n=nums.size();
//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             for(int k=j+1;k<n;k++){
//                 if(nums[i]+nums[j]+nums[k]==0){
//                     vector<int>triplet={nums[i],nums[j],nums[k]};
//                     sort(triplet.begin(), triplet.end());
//                     res.insert(triplet);
//                 }
//             }
//         }
//     }
//     vector<vector<int>> v(res.begin(), res.end());
//     return v;
// }

vector<vector<int>> threeSum(vector<int>& nums) {

    set<vector<int>>res;
    
    int n=nums.size();
    vector<int>nums1=nums;
    sort(nums1.begin(),nums1.end());
    
    for(int i=0;i<n;i++){
        int req = -nums1[i];
        int l=i+1;
        int r=n-1;
        
        while(l<r){
            int sum=nums1[l]+nums1[r];
            if(sum==req){
                res.insert({nums1[i],nums1[l],nums1[r]});
                    l++;
    r--;
            }else if(sum<req){
                l++;
            }else{
                r--;
            }
        }
    }
    vector<vector<int>> v(res.begin(), res.end());
    return v;
}

int main() {
    // Test Case 1: Standard case
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    auto result1 = threeSum(nums1);
    cout << "Test Case 1 Output: ";
    for (auto &triplet : result1) {
        cout << "[";
        for (int x : triplet) cout << x << " ";
        cout << "] ";
    }
    cout << endl;
    // Expected: [-1,-1,2] [-1,0,1]

    // Test Case 2: No triplets
    vector<int> nums2 = {0, 1, 1};
    auto result2 = threeSum(nums2);
    cout << "Test Case 2 Output: ";
    for (auto &triplet : result2) {
        cout << "[";
        for (int x : triplet) cout << x << " ";
        cout << "] ";
    }
    cout << endl;
    // Expected: []

    // Test Case 3: All zeros
    vector<int> nums3 = {0, 0, 0};
    auto result3 = threeSum(nums3);
    cout << "Test Case 3 Output: ";
    for (auto &triplet : result3) {
        cout << "[";
        for (int x : triplet) cout << x << " ";
        cout << "] ";
    }
    cout << endl;
    // Expected: [0,0,0]

    // Test Case 4: Larger input
    vector<int> nums4 = {-2, 0, 1, 1, 2};
    auto result4 = threeSum(nums4);
    cout << "Test Case 4 Output: ";
    for (auto &triplet : result4) {
        cout << "[";
        for (int x : triplet) cout << x << " ";
        cout << "] ";
    }
    cout << endl;
    // Expected: [-2,0,2] [-2,1,1]

    return 0;
}



# TWO POINTER - Two Sum

vector<int> twoSum(vector<int>& nums, int target) {
    
    int l=0;
    int r=nums.size()-1;
    
    vector<pair<int,int>>arr;
    
    for(int i=0;i<nums.size();i++){
        arr.push_back({nums[i],i});
    }
    sort(arr.begin(),arr.end());
    
    while(l<r){
        int sum= arr[l].first+arr[r].first;
        
        if(sum==target){
            return {arr[l].second,arr[r].second};
        }
        else if(sum<target){
            l++;
            
        }else{
            r--;
        }
    }
    return {};

}

TWO POINTER -THREE SUM


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>>res;
        int n=nums.size();

        vector<int>nums1=nums;

        sort(nums1.begin(),nums1.end());

        for(int i=0;i<n;i++){

            if(i>0 &&  nums1[i]== nums1[i-1])continue;

            int target = -nums1[i];
            int l=i+1;
            int r=n-1;
            while(l<r){
                int sum=nums1[l]+nums1[r];
                if(sum==target){
                    res.push_back({nums1[i],nums1[l],nums1[r]});
                    l++;
                    r--;
                    while(l<r && nums1[l]==nums1[l-1] )l++;
                    while(l<r && nums1[r]==nums1[r+1]) r--;
                }else if(sum<target){
                    l++;
                }else{
                    r--;
                }
            }

        }

        
        return res;
        
    }
};


-GROUP ANAGRAM

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<string,vector<string>>freq;
        vector<vector<string>>res;

        for(int i=0;i<strs.size();i++){
            
            string str=strs[i];
            sort(str.begin(),str.end());
            freq[str].push_back(strs[i]);

        }
        for(auto& it : freq){
            res.push_back(it.second);
        }
        return res;
        
    }
};

--max score from cards
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int leftSum=0;
        int rightSum=0;
        int maxScore=INT_MIN;

        for(int i=0;i<k;i++){
            leftSum+=cardPoints[i];
        }
        maxScore=leftSum+rightSum;
        int rightIndex=cardPoints.size()-1;

        for(int i=k-1;i>=0;i--){
            leftSum-=cardPoints[i];
            rightSum+=cardPoints[rightIndex];
            rightIndex--;
            maxScore=max(maxScore,leftSum+rightSum);
        }
        return maxScore;
    }
};

-LONGEST SUBSTRING WITHOUT REPEATING CHAR
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        map<int,int>freq;
        int l=0;
        int maxLength=0;

        for(int r=0;r<s.size();r++){

            if(freq.find(s[r]) != freq.end() &&  freq[s[r]]>= l){
                l=freq[s[r]]+1;
            }
            freq[s[r]]=r;

            maxLength=max(maxLength,r-l+1);
        }

        return maxLength;

        
    }
};

--VALID PALINDROME
class Solution {
public:
    bool isPalindrome(string s) {
        int l=0;
        int r=s.size()-1;

        while(l<r){
            while(l<r && !isalnum(s[l]))l++;
            while(l<r && !isalnum(s[r]))r--;
            if(tolower(s[l])!= tolower(s[r]))return false;
            l++;
            r--;
        }
        return true;
    }
};

-LONGES CONSECUTIVE SUBSEQEUNCE SORTED VERSION

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        
        vector<int>nums1=nums;
        sort(nums1.begin(),nums1.end());

        int count=1;
        int maxCount=1;

        for(int i=1;i<nums1.size();i++){
            if (nums1[i] == nums1[i-1]) {
                continue; // skip duplicate
            } 
            if(nums1[i] ==nums1[i-1]+1){
                count++;
            }else{
                count=1;
            }
            maxCount=max(count,maxCount);
        }

        return maxCount;
    }
};
