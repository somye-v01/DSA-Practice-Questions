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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len = 0;
        while(temp != nullptr){
            len++;
            temp=temp->next;
        }
        // cout << len << endl;
        int cn = 0;
        int rem = len - n ;
        if(rem==0){
            head = head->next;
            return head;
        }
        ListNode* temp2 = head;
        while(temp2!=nullptr){
            if(cn == rem-1){
                if(temp2->next->next != nullptr){
                    temp2->next = temp2->next->next;
                }
                else{
                    temp2->next=nullptr;
                }
            }
                cn++;
                temp2 = temp2->next;
            
        }
        return head;
    }
};