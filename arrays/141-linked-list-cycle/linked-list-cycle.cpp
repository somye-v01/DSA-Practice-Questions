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
       
        set<ListNode*> s;
        ListNode* temp = head;
       while (temp != nullptr) {
        if (s.find(temp) != s.end()) {
            //cycle
            return true;
        }
        s.insert(temp);
        temp = temp->next;
    }

    return false;
}
};