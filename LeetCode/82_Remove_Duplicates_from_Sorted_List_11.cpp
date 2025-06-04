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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;
        while(curr){
            if(curr->next && curr->val==curr->next->val){
                int a = curr->val;
                while(curr && curr->val==a){
                    curr=curr->next;
                }
                prev->next = curr;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
            
        }
        return dummy->next;
    }
};