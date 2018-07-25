#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class Node{
friend class LRUCache;
public:
    Node(int v) : value(v), next(0), prev(0) { }
private:
    int value;
    Node* next;
    Node* prev;
};

class LRUCache {
public:
    LRUCache(int c) : capacity(c), numberOfElements(0), head(0), tail(0) { }
    
    int get(int key) {
        if (keyValue[key] != 0){
            accessed(key);
            return keyValue[key];
        } else {
            keyValue.erase(key);
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (keyValue[key] == 0){
            ++numberOfElements;
        } 

        keyValue[key] = value;    
        accessed(key);

        if (numberOfElements > capacity){
            evict();
        }        
    }


private:
    int capacity;
    int numberOfElements;
    unordered_map<int, int> keyValue;
    unordered_map<int, Node*> nodePointers;
    // doubly linked list. tail gets evicted if capacity exceeded.
    //list<int> lastAccessed;   
    Node* head; // least recently accessed node, to be popped
    Node* tail; // most recently accessed node

    void accessed(int key){
        // erase key
        if (nodePointers[key] != 0){
            erase(nodePointers[key]);
            nodePointers.erase(key);
        }

        // put the accessed key at the very back of the list
        push_back(key);
        nodePointers[key] = tail;
    }

    void evict(){
        // erase element from hashmap and pop from list
        keyValue.erase(head->value);
        nodePointers.erase(head->value);
        pop_head();
        --numberOfElements;
    }

    void push_back(int key){
        if (!head){
            head = tail = new Node(key);
        } else {
            Node* temp = tail;
            tail = new Node(key);
            temp->prev = tail;
            tail->next = temp;
        }
    }

    void pop_head(){
        if (!head){
            return;
        } else {
            Node* temp = head->prev;
            delete head;
            if (temp){
                temp->next = 0;
            }
            head = temp;
        }
    }

    void erase(Node* node){
        if (!node){
            return;
        }
        if (node == head){
            pop_head();
        }
        else if (node == tail){
            tail = node->next;
            tail->prev = 0;
            delete node;
        }
        else {
            // node in the middle
            node->next->prev = node->prev;
            node->prev->next = node->next;
            delete node;
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
    obj->put(1,1);
    obj->put(2,3); 
    obj->put(4,1); // pops 1
    cout << obj->get(1) << endl; // returns -1
    cout << obj->get(2) << endl; // returns 3
    obj->put(3,30); // pops 1
    cout << obj->get(1) << endl; // returns -1
    obj->put(4,40); // pops 1
    obj->put(5,50); // pops 3
    cout << obj->get(1) << endl; // returns -1
    cout << obj->get(3) << endl; // returns -1
    cout << obj->get(4) << endl; // returns 40*/

    return 0;
}