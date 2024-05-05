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
    void deleteNode(ListNode* node) {
        int val = node->val;
        if(node->next){
            int temp = node->next->val;
            node->next->val = val;
            node->val = temp;
            node->next = node->next->next;
        }
        // return node;
        
    }
};