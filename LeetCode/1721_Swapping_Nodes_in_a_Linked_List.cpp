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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL)return NULL;
        if(head->next==NULL)return head;

        int length = 1;
        ListNode* lengthptr = head;
        while(lengthptr){
            length++;
            lengthptr = lengthptr->next;
        }

        ListNode* left = head;
        ListNode* right = head;
        for(int i=1;i<k;i++){
            left = left->next;
        }

        for(int i=0;i<length - k-1;i++){
            right = right->next;
        }

        swap(right->val,left->val);
        return head;

    }
};