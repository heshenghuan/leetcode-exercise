struct cacheNode{
    int key;
    int value;
    cacheNode(int k, int v) : key(k), value(v) {}
};

class LRUCache{
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key) != cacheMap.end()) {
            auto it = cacheMap[key];
            // Update position
            cacheMem.splice(cacheMem.begin(), cacheMem, it);
            cacheMap[key] = cacheMem.begin();
            return cacheMem.begin()->value;
        }
        else return -1;
    }
    
    void set(int key, int value) {
        if(cacheMap.find(key) == cacheMap.end()){
            // new data come, need insert
            if(cacheMem.size() == size) {
                // the cache is full, need erase the tail node
                cacheMap.erase(cacheMem.back().key);
                cacheMem.pop_back();
            }
            cacheMem.push_front(cacheNode(key, value));
            cacheMap[key] = cacheMem.begin();
        }
        else {
            // the key is already in cache
            // update its value and position in cache
            auto it = cacheMap[key];
            cacheMem.splice(cacheMem.begin(), cacheMem, it);
            cacheMap[key] = cacheMem.begin();
            cacheMem.begin()->value = value;
        }
    }
private:
    int size;
    list<cacheNode> cacheMem;
    map<int, list<cacheNode>::iterator > cacheMap;
};