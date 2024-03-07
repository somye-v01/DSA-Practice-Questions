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
    ListNode* middleNode(ListNode* head) {
        ListNode* sl = head;
        ListNode* ft = head;
        while(ft!=nullptr){
            if(ft->next){
                sl = sl->next;
                ft = ft->next;
            }
            ft = ft->next;
        }
        return sl;
    }
};