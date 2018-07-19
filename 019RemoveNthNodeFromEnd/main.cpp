#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *end = head;
        ListNode *trail = new ListNode(0);
        ListNode *to_remove = head; 
        trail->next = to_remove;

        for (int i =0; i != n; ++i)
            end = end->next;

        while(end){
            end = end->next;
            to_remove = to_remove->next;
        }

        while(trail->next != to_remove && trail->next)
            trail = trail->next;
        
        
        if (!trail->next){
            // deleting the only node
            return 0;
        } else if (to_remove == head){
            // deleting the head, return the node after head
            ListNode* temp = head->next;
            delete head;
            return temp;
        } else {
            // deleting from middle or end, connect neighboring nodes of the removal node
            trail->next = to_remove->next;
            delete to_remove;
            return head;
        }
        
    }
};

int main(){
    Solution solution;
    ListNode* one = new ListNode(1);
    ListNode* two = new ListNode(2);
    ListNode* three = new ListNode(3);
    ListNode* four = new ListNode(4);
    ListNode* five = new ListNode(5);
    one->next = two;
    /*two->next = three;
    three->next = four;
    four->next = five;*/
    ListNode* temp = solution.removeNthFromEnd(one, 2);

    while (temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}