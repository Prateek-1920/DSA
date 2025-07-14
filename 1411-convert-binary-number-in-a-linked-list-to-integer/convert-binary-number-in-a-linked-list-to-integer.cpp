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
    int todec(string s){
        int ans = 0;
        int n = s.length();
        for(int i=0;i<s.length();i++){
            ans = ans + (s[i]-'0')*pow(2,n-1);
            n--;
        }
        return ans;
    }
public:
    int getDecimalValue(ListNode* head) {
        if(head==NULL)return 0;

        string s = "";
        ListNode* ptr = head;

        while(ptr){
            s+=to_string(ptr->val);
            ptr = ptr->next;
        }
        return todec(s);
    }
};