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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> set;
        for(int i : nums){
            set.insert(i);
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        if(head==NULL)return NULL;
        if(head->next==NULL)return head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr){
            if(set.find(curr->val)!=set.end()){
                curr=curr->next;
                prev->next=curr;
            }
            else{
                curr = curr->next;
                prev = prev->next;
            }
        }
        return dummy->next;
    }
};