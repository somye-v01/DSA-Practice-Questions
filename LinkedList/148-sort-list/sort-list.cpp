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

    vector<int> sorted(ListNode* head){
        vector<int> temp;
        while(head != nullptr ){
            temp.push_back(head->val);
            head = head->next;
        }
        return temp;
    }

    ListNode* sortList(ListNode* head) {
        if(!head) return NULL;
        vector<int> v = sorted(head);
        sort(v.begin(),v.end());
        for(auto x : v){
            cout << x << " ";
        }
        ListNode* prev = new ListNode(0) ;
        ListNode* curr = prev;
        for(int i = 0; i < v.size(); i++){
            ListNode* temp = new ListNode(v[i]);
            prev->next = temp;
            prev = temp;
        }
        return curr->next;
    }
};