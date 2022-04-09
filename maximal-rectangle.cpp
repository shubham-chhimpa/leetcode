
//https://leetcode.com/problems/maximal-rectangle

// 85. Maximal Rectangle

class Solution {
public:

    void nsl(vector<int> &heights,vector<int> &left){
        int n = heights.size();
        stack<pair<int,int>> st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first >= heights[i]){
                st.pop();
            }
            
            if(st.empty()){
                left.push_back(-1);
            }else{
                left.push_back(st.top().second);
            }
            
            st.push({heights[i],i});
        }
    }
    
    void nsr(vector<int> &heights,vector<int> &right){
        int n = heights.size();
        stack<pair<int,int>> st;
        for(int i= n-1;i>=0;i--){
            while(!st.empty() && st.top().first >= heights[i]){
                st.pop();
            }
            
            if(st.empty()){
                right.push_back(n);
            }else{
                right.push_back(st.top().second);
            }
            
            st.push({heights[i],i});
        }
        
        reverse(right.begin(),right.end());
    }
    
    int mah(vector<int> &heights){
        int n = heights.size();
        vector<int> left;
        vector<int> right;
        
        nsr(heights,right);
        nsl(heights,left);
        
        int mx = INT_MIN;
        
        for(int i=0;i<n;i++){
            left[i] = (right[i]-left[i]-1)*heights[i];
            mx = max(mx,left[i]);
        }
        
        return mx;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols,0);
        int mx = INT_MIN;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                
                if(matrix[i][j] == '0'){
                    heights[j] = 0;    
                }else{
                    heights[j] +=1; 
                }
                
            }
              int area = mah(heights);
                cout<<area<<"\n";
                mx = max(mx,area);
        }
        
        return mx;
    }
};
