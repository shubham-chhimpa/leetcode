// 146. LRU Cache

//https://leetcode.com/problems/lru-cache/


class LRUCache {
public:
    unordered_map<int,list<pair<int,int>>::iterator> cache;
    list<pair<int,int>> q;
    int cap  = 0;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    void refresh(int key,int value){
        q.erase(cache[key]);
        q.push_front({key,value});
        cache[key] = q.begin();
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            refresh(key,(*cache[key]).second);
            return (*cache[key]).second;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(cache.find(key) == cache.end()){
            if(q.size()>=cap){
                cache.erase(q.back().first);
                q.pop_back();
                
            }
            q.push_front({key,value});
            cache[key] = q.begin();
        }else{
            
            refresh(key,value);
        }
        
      
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
