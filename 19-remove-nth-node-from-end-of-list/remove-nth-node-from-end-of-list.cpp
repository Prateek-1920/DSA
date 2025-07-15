// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode *ptr = head;
//         while(n!=0 && ptr){
//             ptr = ptr->next;
//             n--;
//         }

//         if (!ptr) return head->next;

//         ListNode *temp = head;
//         while(ptr->next){
//             temp=temp->next;
//             ptr = ptr->next;
//         }
//         temp->next=temp->next->next;
//         return head;
//     }
// };


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)return NULL;
        ListNode *ptr = head;
        int len = 1;
        while(ptr->next){
            ptr = ptr->next;
            len++;
        }

        int node = len-n;
        if(node==0){
            if(head->next==NULL){
                return NULL;
            }
            else{
                return head->next;
            }
        }
        ptr=head;
        ListNode* prev = nullptr;
        while(node){
            prev = ptr;
            ptr = ptr->next;
            node--;
        }
        prev->next = ptr->next;
        return head;
    }
};