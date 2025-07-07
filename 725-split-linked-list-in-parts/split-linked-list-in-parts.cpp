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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if(head==NULL)return vector<ListNode*>(k,NULL);
        vector<ListNode*> ans;
        int len = 0;
        ListNode* ptr=head;

        while(ptr){
            len++;
            ptr = ptr->next;
        }

        int basesize = len/k;
        int extra = len%k;

        ptr = head;
        for(int i=0;i<k;i++){
            ListNode* parthead = ptr;
            int currsize = basesize+ (extra>0?1:0);
            extra--;
            ListNode* prev = nullptr;
            for(int i=0;i<currsize;i++){
                prev = ptr;
                if(ptr!=NULL){
                    ptr = ptr->next;
                }
            }
            if(prev!=NULL){
                prev->next=NULL;
            }
            ans.push_back(parthead);
        }
        return ans;
    }
};