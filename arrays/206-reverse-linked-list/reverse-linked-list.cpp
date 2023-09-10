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

    ListNode* reverseListHelper(ListNode* prev, ListNode* curr){
        while(curr!=nullptr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == NULL){
            return NULL;
        }
        if (head->next == NULL){
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        return reverseListHelper(prev,curr);
    }
};