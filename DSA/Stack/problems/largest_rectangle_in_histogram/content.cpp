class Solution {
public:

    vector<int> nextSmallerElement(vector<int>&height){

        vector<int>res(height.size());
        stack<int>st;

        for(int i=height.size()-1;i>=0;i--){

            while(!st.empty() and height[st.top()] >= height[i]){
                st.pop();
            }
            if(st.empty()){
                res[i]=height.size();
            }else{
                res[i]=st.top();
            }
            st.push(i);
        }
        return res;

    }

    vector<int> previousSmallerElement(vector<int>&height){
        vector<int>res(height.size());
        stack<int>st;

        for(int i=0;i<height.size();i++){
            while(!st.empty() &&height[st.top()]> height[i]){
                st.pop();
            }

            if(st.empty()){
                res[i]=-1;
            }else{
                res[i]=st.top();
            }
            st.push(i);
        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {

        vector<int>nse=nextSmallerElement(heights);
        vector<int>pse=previousSmallerElement(heights);


        int maxArea=0;
        for(int i=0;i<heights.size();i++){
            int prevSmaller = pse[i];
            int nextSmaller = nse[i];

            maxArea=max(maxArea,heights[i]*(nextSmaller-prevSmaller-1));
            
        }
        return maxArea;
        
    }
};