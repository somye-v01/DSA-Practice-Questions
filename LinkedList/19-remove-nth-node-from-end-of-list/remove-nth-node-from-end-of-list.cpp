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

    int getLength(ListNode* head){
        int count = 0;
        ListNode* temp = head;
        while (temp!=nullptr){
            temp = temp->next;
            count++;
        }
        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return head;
        }
        int length = getLength(head);
        int len = length - n;
        
        if(length == 1){
            return NULL;
        }
        if(length < n){
            return head;
        }
        if(length == n){
        head = head -> next;
        return head;
    }
        ListNode* temp = head;
        for(int i = 1; i < len; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        

        return head;
    }
};
