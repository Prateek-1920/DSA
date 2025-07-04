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
private:
ListNode* reverse(ListNode* head){
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* temp = NULL;
     while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr= temp;
        }
        return prev;
}

public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prevslow = nullptr;

        while(fast && fast->next){
            prevslow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head2 = reverse(slow);

        if (prevslow) {
            prevslow->next = nullptr;
        }


        // ListNode* prev = nullptr;
        // ListNode* curr = slow;
        // while(curr){
        //     ListNode* temp = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr= temp;
        // }

        ListNode* p1 = head;
        ListNode* p2 = head2;

        while(p1 && p2){
            ListNode* p1next = p1->next;
            ListNode* p2next = p2->next;

            p1->next = p2;
            if(p1next){
                p2->next = p1next;
            }

            p1 = p1next;
            p2 = p2next;
        }
    }
};