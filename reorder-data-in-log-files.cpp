# leetcode

// 937. Reorder Data in Log Files
// https://leetcode.com/problems/reorder-data-in-log-files/

class Solution {
public:
    
    static pair<string,string> split_log(string log){
        int n = log.size();
       
        
        for(int i=0;i<n;i++){
            if(log[i] == ' '){
                string identifier = log.substr(0,i-1);
                string data = log.substr(i+1,n);
                return {identifier,data};
            }
        }
        
        return {};
    } 
    
    static bool compare_logs(string a,string b){
        auto split_a = split_log(a);
        auto split_b = split_log(b);
        
        if(split_a.second == split_b.second) return split_a.first < split_b.first;
        
        return split_a.second < split_b.second;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letter_logs;
        for(auto log : logs){
             auto splitted_log = split_log(log);
            if(!isdigit(splitted_log.second[0])){
                letter_logs.push_back(log);
            }
        }
      
        sort(letter_logs.begin(),letter_logs.end(),compare_logs);
        for(auto log : logs){
             auto splitted_log = split_log(log);
            if(isdigit(splitted_log.second[0])){
                letter_logs.push_back(log);
            }
        }
        return letter_logs;
    }
};
