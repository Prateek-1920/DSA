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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0,head);
        unordered_map<int,ListNode*> prefix; 
        prefix[0] = dummy;
        ListNode* curr = head;
        int prefixsum = 0;

        while(curr){
            prefixsum+=curr->val;

            if(prefix.find(prefixsum)!=prefix.end()){
                ListNode* prev = prefix[prefixsum];
                ListNode* temp = prev->next;
                int tempsum = prefixsum;
                while(temp!=curr){
                    tempsum+=temp->val;
                    prefix.erase(tempsum);
                    temp = temp->next;;
                }
                prev->next = curr->next;
            }
            else{
                prefix[prefixsum] = curr;
            }
            curr=curr->next;
        }
        return dummy->next;
    }
};