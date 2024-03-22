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

    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            // cout<<"entering the loop:"<<endl;
            ListNode* nxt = curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }

    ListNode* findMiddle(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next){
            fast=fast->next;
            if(fast->next){
                fast=fast->next;
            }
            slow = slow->next;
        }
        return slow;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* mid = findMiddle(head);
        ListNode* reversedMid = reverse(mid);
        while(reversedMid){
            if(head->val!=reversedMid->val){
                return false;
            }
            head = head->next;
            reversedMid = reversedMid->next;
        }
        return true;
    }
};
