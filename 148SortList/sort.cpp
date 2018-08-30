#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

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
        ListNode* wall = 0;
        ListNode* node = head;
        ListNode* parent1 = 0;
        while(node){
            cout << node->val << endl;
            if(parent1) cout << "parent : " << parent1->val << endl;
            auto minAndParent = findMin(node, parent1);
            swap(node, get<0>(minAndParent), parent1, get<1>(minAndParent));
            cout << "min : " << get<0>(minAndParent)->val << endl;
            cout << "min's parent: " << get<1>(minAndParent)->val << endl;
            parent1 = get<0>(minAndParent);
            node = get<0>(minAndParent)->next;
        }

        return head;
    }

    void swap(ListNode* node1, ListNode* node2, ListNode* parent1, ListNode* parent2){
        if (parent1) parent1->next = node2;
        if (parent2) parent2->next = node1;

        // node1 and node2 is guaranteed to be valid
        node1->next = node2->next;
        node2->next = node1->next;
    }

    pair<ListNode*, ListNode*> findMin(ListNode* start, ListNode* parent){
        ListNode* min = start;
        ListNode* trail = parent;
        while (start){
            cout << "    " << start->val << endl;
            if (start->val < min->val){
                min = start;
                parent = trail;
            }
            trail = start;
            start = start->next;
        }
        cout << "        " << min->val << endl;
        return make_pair(min, parent);
    }
};
int main(){

    return 0;
}