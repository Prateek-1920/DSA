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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;

        while(fast && fast->next){
            fast = fast->next->next;
            ListNode *temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        if(fast!=nullptr){
            slow = slow->next;
            
        }

        while(prev && slow){
                if(prev->val!=slow->val)return false;
                else{
                    prev = prev->next;
                    slow = slow->next;
                }
        }
        return true;
    }
};
