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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> s;
        while (headA != nullptr){
            s.insert(headA);
            headA = headA->next;
        }
        while(headB!=nullptr){
            if(s.find(headB) == s.end()){
                headB=headB->next;
            }
            else{
                return headB;
            }
        }
        return nullptr;
    }
    
};