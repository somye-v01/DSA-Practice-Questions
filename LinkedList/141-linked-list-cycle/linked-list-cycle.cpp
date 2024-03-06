/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        int i = 0;
        map<ListNode*,bool>m;
        while(head!=nullptr){
            if(m[head]==true){
                // cout << "the duplicate im getting is: "<<head->val<<endl;
                return true;
            }
            m[head]=true;
            head=head->next;
        }
        return false;
    }
};