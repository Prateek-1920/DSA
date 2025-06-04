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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        ListNode* ptr = head->next;
        ListNode* curr = head;
        while(curr->next){
            int a = curr->val;
            while(ptr!=NULL && ptr->val<=a){
                ptr=ptr->next;
            }
            ans.push_back((ptr==NULL || ptr->val==a)?0:ptr->val);
            curr = curr->next;
            ptr = curr->next;
        }
        ans.push_back(0);
        return ans;
    }
};