#include <algorithm>
#include <iostream>
#include <queue>

class LRUCache {
public:
    LRUCache(int c) {
        capacity = c;
    }
    
    int get(int key) {
        
    }
    
    void put(int key, int value) {
        keyValue[key] = value;
        accessed(key);

        if (keyOrderQueue.size() > capacity){
            int evictKey = keyOrderQueue.front();
            keyOrderQueue.pop();

        }
        
    }


private:
    int capacity;
    unordered_map<int, int> keyValue;
    queue<int> keyOrderQueue;

    void accessed(int key){
        // move key up to the front of queue 
        if (find(keyOrderQueue.begin(), keyOrderQueue.end(), key) == keyOrderQueue.end()){
            keyOrderQueue.push(key);
        } else {
            // key found, delete it and move up
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main(){
    LRUCache* obj = new LRUCache(2);
    obj->put(2,1);
    int param_1 = obj->get(2);
    return 0;
}