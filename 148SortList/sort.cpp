#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // sorting a singly linked list given head

    }

    void swap(ListNode* node1, ListNode* node2, ListNode* parent1, ListNode* parent2){
        if (parent1) parent1->next = node2;
        if (parent2) parent2->next = node1;

        // node1 and node2 is guaranteed to be valid
        node1->next = node2->next;
        node2->next = node1->next;
    }
};

int main(){

    return 0;
}