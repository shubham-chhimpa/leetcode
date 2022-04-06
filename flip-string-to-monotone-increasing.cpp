// 926. Flip String to Monotone Increasing

// https://leetcode.com/problems /flip-string-to-monotone-increasing

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        
        prefix[0] = (s[0] == '1' ? 1:0);
        // cout<<0<<" "<<prefix[0]<<"\n";
        for(int i=1;i<n;i++){
            if(s[i] == '1'){
                prefix[i] = prefix[i-1]+1; 
                            
            }else{
                prefix[i] = prefix[i-1];
            }
            // cout<< i<<" "<<prefix[i]<<"\n";
        }
        
        suffix[n-1] = (s[n-1]=='0' ? 1 :0);
        // cout<<n-1<<" "<<suffix[0]<<"\n";

        for(int i=n-2;i>=0;i--){
            if(s[i] == '0'){
                suffix[i] = suffix[i+1] +1;
            }else{
                suffix[i] = suffix[i+1];
            }
            // cout<< i<<" "<<suffix[i]<<"\n";

        }
        int flips = INT_MAX;
        for(int i=0;i<n-1;i++){
            flips = min(flips,prefix[i]+suffix[i+1]);
        }
        
        flips = min(prefix[n-1],flips);
        flips = min(suffix[0],flips);
        return flips;
        
    }
};
