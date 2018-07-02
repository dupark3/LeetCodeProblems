
#include <iostream>


using namespace std;

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) { }
};
 

class Solution {
public:
    RandomListNode* copyRandomList(RandomListNode* head) {
        
    }
};

int main(){
    RandomListNode first(5);
    RandomListNode second(7);
    RandomListNode third(9);
    RandomListNode fourth(11);
    
    first.next = &second;
    second.next = &third;
    third.next = &fourth;
    first.random = &third;
    second.random = 0;
    third.random = &first;
    fourth.random = &second;

    Solution solution;
    solution.copyRandomList(&first);
    return 0;
}