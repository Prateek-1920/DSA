/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *head = dummy;
        ListNode * t1 = l1;
        ListNode * t2 = l2;
        int total = 0;
        int carry = 0;

        while(t1||t2||carry){
            total = carry;
            if(t1){
                total+=t1->val;
                t1 = t1->next;
            }
            if(t2){
                total+=t2->val;
                t2 = t2->next;
            }
            int num = total%10;
            carry = total/10;
            dummy->next = new ListNode(num);
            dummy = dummy->next;
        }
        return head->next;
    }
};