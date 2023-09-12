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

    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next==nullptr){
            return false;
        }
       
    //     set<ListNode*> s;
    //     ListNode* temp = head;
    //    while (temp != nullptr) {
    //     if (s.find(temp) != s.end()) {
    //         //cycle
    //         return true;
    //     }
    //     s.insert(temp);
    //     temp = temp->next;
    // }

    // return false;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(slow!=fast){
        if (fast == nullptr || fast->next == nullptr ){
            return false;
        }
        
        fast = fast->next->next;
        slow = slow->next;
        
    }
    return true;
}
};