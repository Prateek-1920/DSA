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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)return NULL;
        if(head->next==NULL)return head;

        ListNode *oddptr = head;
        ListNode *evenptr = head->next;
        ListNode *evenstart = evenptr;
        while( evenptr!=nullptr && evenptr->next!=nullptr){
            oddptr->next = evenptr->next;
            oddptr=evenptr->next;
            evenptr->next = oddptr->next;
            evenptr = oddptr->next;
        }
        oddptr->next = evenstart;
        return head;
    }
};
