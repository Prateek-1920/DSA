/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* getend(ListNode* head, int &len){
        if(head==NULL)return NULL;
        ListNode* temp = head;
        while(temp->next){
            temp = temp->next;
            len++;
        }
        return temp;
    }

    ListNode *intersect(ListNode* l1, ListNode* l2, int len1, int len2){ //len1 > len2
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        while(len1!=len2){
            ptr1 = ptr1->next;
            len1--;
        }
        while(ptr1!=ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = 1;
        int l2 = 1;

        ListNode* Aend = getend(headA,l1);
        ListNode* Bend = getend(headB,l2);

        if(Aend!=Bend){
            return NULL;
        }

        cout<<l1<<" "<<l2;

        ListNode* ptr;

        if(l1>l2){
           return intersect(headA, headB, l1,l2);
        }
        else{
           return intersect(headB, headA, l2, l1);
        }

        return NULL;

    }
};