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

    vector<int> convertArr(ListNode* head){
        vector<int> v;
        ListNode* temp = head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        return v;
    }

    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> ll = convertArr(head);
        int n = ll.size();

        for (int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j<n;j++){
                sum+=ll[j];
                if(sum == 0){
                    for(int st = i; st<=j; st++){
                        ll[st]=0;
                    }
                   
                }
            }
        }

        
        ListNode* ans = new ListNode(0);
        ListNode* head1 = ans;
        for(int i = 0; i < n; i++){
            if(ll[i]!=0){
                ans->next = new ListNode(ll[i]);
                ans = ans->next;
            }
        }
       
        return head1->next;
    }
};