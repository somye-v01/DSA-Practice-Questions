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
        while(head){
            ListNode* nxt = head->next;
            head->next=prev;
            prev=head;
            head=nxt;
        }
        return prev;
    }

    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

    void reorderList(ListNode* head) {
        //store reverse, mid, do zig-zag
        ListNode* mid = findMiddle(head);
        ListNode* rev = reverse(mid->next);
        mid->next=nullptr;
        ListNode* curr = head;
        while(rev){
            ListNode* temp = curr->next;
            curr->next = rev;
            rev=rev->next;
            curr->next->next = temp;
            curr=temp;
        }
    }
};