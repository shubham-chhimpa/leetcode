# leetcode


//https://leetcode.com/problems/search-suggestions-system/submissions/



class Solution {
public:
    
    class TrieNode{
        public :
        TrieNode* children[26];
        bool isEnd = false; 
        
        TrieNode(){
           for(int i=0;i<26;i++){
               this->children[i] = NULL;
           }
        }
        
        
    };
    
    class Trie {
      
        public : 
            TrieNode* root;
            Trie(){
                root = new TrieNode();
            }
        
        void insert(string &word){
            TrieNode* curr = root;
            for(char c : word){
                int index = c - 'a';
                if(curr->children[index] == NULL){
                    curr->children[index] = new TrieNode();
                }
                    curr = curr->children[index];
            
        }
        
        curr->isEnd = true;
    }
    
        vector<string> search(string &word){
            vector<string> sugg;
            if(word == "") return sugg;
            TrieNode* curr = root;
            for(char c : word){
                int index = c - 'a';

                if(curr->children[index] == NULL) return {};
                curr = curr->children[index];
            }
            searchRecur(sugg,curr,word);
            return sugg;;
        }
        
        void searchRecur(vector<string> &sugg,TrieNode* curr,string &word){
            if(curr ==NULL ) return;
            if(sugg.size() >=3) return;
            if(curr->isEnd){
                sugg.push_back(word);
            }
            for(int i=0;i<26;i++){
                if(curr->children[i]){
                    string tmp = word+char(i+'a');
                    searchRecur(sugg,curr->children[i],tmp);
                }
            }
            
        }
    };
    
 
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        Trie* trie = new Trie();
        
        for(auto s : products){
            trie->insert(s);
        }
        string msg;
        for(auto c : searchWord){
            
            msg.push_back(c);
            ans.push_back(trie->search(msg));
        }
       
        return ans;
    }
};
