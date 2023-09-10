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

    ListNode* reverseListHelper(ListNode* curr, ListNode* prev){
        if (curr == NULL){
            return prev;
        }
        ListNode* forward = curr->next;
        curr->next = prev;
        return reverseListHelper(forward,curr);
        
        
    }

    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
    return reverseListHelper(curr,prev);
    
    }
};