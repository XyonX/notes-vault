#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int ast : asteroids){
            bool destroyed = false; 
            // If asteroid is moving right (positive), push it to stack
            if(ast > 0) {
                st.push(ast);
            } else {
                // Asteroid is moving left (negative)
                // Check for collisions with right-moving asteroids in stack
                while(!st.empty() && st.top() > 0){
                    // If both asteroids are of same size, both get destroyed
                    if(ast + st.top() == 0) {
                        st.pop();
                        destroyed = true; 
                        break;
                    }
                    // If left-moving asteroid is larger, destroy the right-moving one
                    else if(abs(ast) > st.top()){
                        st.pop();
                    }
                    // If right-moving asteroid is larger, destroy the left-moving one
                    else if (abs(ast) < st.top()){
                        destroyed = true;
                        break;
                    }
                }
                // If current asteroid survived all collisions, add it to stack
                if(!destroyed)
                    st.push(ast);
            }
        }

        vector<int> res(st.size());
        for(int i = st.size() - 1; i >= 0; i--){
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};

// Test function
int main() {
    Solution solution;
    
    // Test case 1: [5,10,-5] => [5,10]
    vector<int> asteroids1 = {5, 10, -5};
    vector<int> result1 = solution.asteroidCollision(asteroids1);
    cout << "Test 1: ";
    for (int x : result1) cout << x << " ";
    cout << endl;

    // Test case 2: [8,-8] => []
    vector<int> asteroids2 = {8, -8};
    vector<int> result2 = solution.asteroidCollision(asteroids2);
    cout << "Test 2: ";
    for (int x : result2) cout << x << " ";
    cout << endl;

    // Test case 3: [10,2,-5] => [10]
    vector<int> asteroids3 = {10, 2, -5};
    vector<int> result3 = solution.asteroidCollision(asteroids3);
    cout << "Test 3: ";
    for (int x : result3) cout << x << " ";
    cout << endl;

    // Test case 4: [-2,-1,1,2] => [-2,-1,1,2]
    vector<int> asteroids4 = {-2, -1, 1, 2};
    vector<int> result4 = solution.asteroidCollision(asteroids4);
    cout << "Test 4: ";
    for (int x : result4) cout << x << " ";
    cout << endl;

    // Test case 5: [1,-2,10,-5] => [-2,10]
    vector<int> asteroids5 = {1, -2, 10, -5};
    vector<int> result5 = solution.asteroidCollision(asteroids5);
    cout << "Test 5: ";
    for (int x : result5) cout << x << " ";
    cout << endl;

    return 0;
}