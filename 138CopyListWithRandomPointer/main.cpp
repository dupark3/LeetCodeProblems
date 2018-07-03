#include <iostream>
#include <vector>

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
        if (head){
            RandomListNode* new_head = new RandomListNode(head->label);
            RandomListNode* pointer = head;
            RandomListNode* new_pointer = new_head;
            
            // vector rand_indexes stores the node index that the rand pointer points to
            // store -1 if rand points to null, since 0 would be pointing to the head
            vector<int> rand_indexes;

            while (pointer){
                // allocate memory for new node for the new list
                if (pointer->next){
                    new_pointer->next = new RandomListNode(pointer->next->label);
                }
                
                // store index that the random pointer points to
                // can't set the new list's random pointer yet since it may not
                // have been allocated yet at this point
                if (pointer->random){
                    int index = 0;
                    RandomListNode* rand_pointer = head;
                    while(pointer->random != rand_pointer){
                        rand_pointer = rand_pointer->next;
                        ++index;
                    }
                    rand_indexes.push_back(index);
                } else {
                    rand_indexes.push_back(-1);
                }
                pointer = pointer->next;
                new_pointer = new_pointer->next;
            }

            // reset pointers to the beginning of the list. 
            // set rand_pointer to the new_head now to advance through the 
            // new list and set equal to each node's rand in the new list
            pointer = head;
            new_pointer = new_head;
            RandomListNode* rand_pointer = new_head;
            int list_size = rand_indexes.size();

            for(int i = 0; i != list_size; ++i){
                if (rand_indexes[i] != -1){
                    for (int j = 0; j != rand_indexes[i]; ++j){
                        rand_pointer = rand_pointer->next;
                    }
                    new_pointer->random = rand_pointer;
                }

                new_pointer = new_pointer->next;
                rand_pointer = new_head;
            }

            return new_head;
        }

        return 0;
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