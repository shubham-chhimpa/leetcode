
// https://leetcode.com/problems/largest-rectangle-in-histogram


// 84. Largest Rectangle in Histogram



class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left_smaller;
        vector<int> right_smaller;
        int n = heights.size();
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first>= heights[i]){
                st.pop();
            }
            if(st.empty()){
                left_smaller.push_back(-1);
            }else{
                left_smaller.push_back(st.top().second);
            }
            
            st.push({heights[i],i});
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first >= heights[i]){
                st.pop();
            }
            
            if(st.empty()){
                right_smaller.push_back(n);
            }else{
                right_smaller.push_back(st.top().second);
            }
            
            st.push({heights[i],i});
        }
        
        reverse(right_smaller.begin(),right_smaller.end());
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            left_smaller[i] = (right_smaller[i] - left_smaller[i] -1)*heights[i];
            mx = max(mx,left_smaller[i]);
        }
        
        return mx;
    }
};
