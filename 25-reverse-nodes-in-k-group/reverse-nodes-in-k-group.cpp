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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k<=1){
            return head;
        }

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevgroupend = dummy;

        while(true){
            ListNode* group = prevgroupend;
            for(int i=0;i<k && group!=NULL;i++){
                group = group->next;
            }
            if(group==NULL){
                break;
            }

            ListNode* groupstart = prevgroupend->next;
            ListNode* nextgroupstart = group->next;

            ListNode* prev = nextgroupstart;
            ListNode* curr = groupstart;

            while(curr!=nextgroupstart){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            prevgroupend->next = group;
            prevgroupend = groupstart;

            
        }
        return dummy->next;
    }
};