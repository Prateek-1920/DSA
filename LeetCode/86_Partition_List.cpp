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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lesslist = new ListNode(0,nullptr);
        ListNode* ptr=head;
        ListNode* newlistptr = lesslist;

        while(ptr){
            if(ptr->val<x){
                newlistptr->next = new ListNode(ptr->val,nullptr);
                newlistptr = newlistptr->next;
            }
            ptr=ptr->next;
        }

        ptr = head;
        while(ptr){
            if(ptr->val>=x){
                newlistptr->next = new ListNode(ptr->val,nullptr);
                newlistptr = newlistptr->next;
            }
            ptr=ptr->next;
        }

        return lesslist->next;
        
    }
};