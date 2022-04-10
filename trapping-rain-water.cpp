//https://leetcode.com/problems/trapping-rain-water/

// 42. Trapping Rain Water


class Solution {
public:

    int trap(vector<int>& height) {
        int  n = height.size();
        
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        int mx = INT_MIN;
        for(int i=1;i<n;i++){
            mx = max(mx,height[i-1]);
            left[i] = mx;
        }
        
        mx = INT_MIN;
        
        for(int i=n-2;i>=0;i--){
            mx = max(mx,height[i+1]);
            right[i] = mx;
        }
        
        int sum = 0;
        for(int i=0;i<n;i++){
            
            int curr =min(left[i],right[i])-height[i]; 
            if(curr>0){
                sum+=curr;
            }
        }
        
        return sum;
    }
};
