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

    int getlength(ListNode* head){
        ListNode* temp = head;
        int len = 0;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL||k==0) {
            return head;
        }

        int len = getlength(head);
        ListNode* lastNode = head;
        k = k%len;
        int las =  len-k ;
        while(len>1){
            lastNode = lastNode->next;
            --len;
        }
        lastNode->next = head;

        ListNode* newHead = head;
        for (int i = 0; i < las - 1; i++) {
            newHead = newHead->next;
        }
        head = newHead->next;
        newHead->next = nullptr;
      
        return head;

    }
};