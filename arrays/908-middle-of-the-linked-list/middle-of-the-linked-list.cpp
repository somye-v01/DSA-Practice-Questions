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
    ListNode* middleNode(ListNode* head) { //fast and slow pointer
        //fast and slow pointer
        if (head == nullptr){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;

        while(fast->next!=nullptr){
            fast = fast->next;
            if(fast->next !=NULL){
                fast = fast->next;
                slow = slow->next;
            }
            else{
                return slow->next;
            }
        }
        return slow;
    }
};