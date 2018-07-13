#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
friend class Solution;
public:        
    ListNode(int x) : val(x), next(NULL) { }
    void print(){
        ListNode* pointer = this;
        while (pointer){
            cout << pointer->val << " ";
            pointer = pointer->next;
        }
    }
private:
    int val;
    ListNode *next;
    
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if (!l2) return l1;
        
        ListNode* head =  0;
        ListNode* current = head;
        int sum = 0;
        int carryOver = 0;

        while(l1 || l2 || carryOver != 0){
            sum = carryOver;
            if (l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2){
                sum += l2->val;
                l2 = l2->next;
            }
            
            carryOver = sum / 10;
            sum = sum % 10;

            if (!head){
                head = new ListNode(sum);
                current = head;
            } else {
                ListNode* newDigit = new ListNode(sum);
                current->next = newDigit;
                current = newDigit;
            }
            
        }
        return head;

    }
};

int main(){
    Solution solution;
    ListNode* listnode1 = new ListNode(5);
    ListNode* listnode2 = new ListNode(9);
    ListNode* result = solution.addTwoNumbers(listnode1, listnode2);
    result->print();
    return 0;
}