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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return {-1,-1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nxt = head->next->next;
        vector<int> cri_pts;
        int pos = 1;

        while(nxt){
            if((curr->val<prev->val && curr->val< nxt->val) || (curr->val>prev->val && curr->val>nxt->val)){
                cri_pts.push_back(pos);
            }
            pos++;
            prev = prev->next;
            curr = curr->next;
            nxt = nxt->next;
        }

        int size = cri_pts.size();
        if(size<2)return {-1,-1};
        
        int maxdist = cri_pts[size-1]-cri_pts[0];
        int mindist = INT_MAX;
        for(int i=1;i<size;i++){
            mindist = min(mindist,cri_pts[i]-cri_pts[i-1]);
        }

        return {mindist,maxdist};

    }
};