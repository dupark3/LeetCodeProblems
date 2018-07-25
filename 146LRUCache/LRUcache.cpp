#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;


class LRUCache {
public:
    LRUCache(int c) : capacity(c), numberOfElements(0) { }
    
    int get(int key) {
        if (keyValue.find(key) != keyValue.end()){
            accessed(key);
            return keyValue[key];
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (keyValue.find(key) == keyValue.end()){
            keyValue[key] = value;
            ++numberOfElements;
        } else {
            keyValue[key] = value;
        }
        accessed(key);
        if (numberOfElements > capacity){
            evict();
        }
    }


private:
    int capacity;
    int numberOfElements;
    unordered_map<int, int> keyValue;
    unordered_map<int, list<int>::iterator> listIterators;
    // doubly linked list. tail gets evicted if capacity exceeded.
    list<int> lastAccessed;   

    void accessed(int key){
        // erase key
        if (listIterators.find(key) != listIterators.end()){
            lastAccessed.erase(listIterators[key]);
            listIterators.erase(key);
        }
/*        // erase key from anywhere in the list if it is found
        auto it = find(lastAccessed.begin(), lastAccessed.end(), key);
        if (it != lastAccessed.end()){
            lastAccessed.erase(it);
        }*/

        // put the accessed key at the very back of the list
        lastAccessed.push_back(key);
        auto it = lastAccessed.end();
        listIterators[key] = --it;
    }

    void evict(){
        // erase element from hashmap and pop from list
        keyValue.erase(lastAccessed.front());
        listIterators.erase(lastAccessed.front());
        lastAccessed.pop_front();
        --numberOfElements;
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
    obj->put(1,1);
    obj->put(2,3);
    obj->put(4,1);
    cout << obj->get(1) << endl; // returns -1
    cout << obj->get(2) << endl; // returns 3
    /*obj->put(3,30); // pops 2
    cout << obj->get(2) << endl; // returns -1
    obj->put(4,40); // pops 1
    obj->put(5,50); // pops 3
    cout << obj->get(1) << endl; // returns -1
    cout << obj->get(3) << endl; // returns -1
    cout << obj->get(4) << endl; // returns 40*/

    return 0;
}