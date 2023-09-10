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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2; // If list1 is empty, return list2
        }
        if (list2 == nullptr) {
            return list1; // If list2 is empty, return list1
        }
        ListNode* dummynode = new ListNode(-1);
        ListNode* dummyptr = dummynode;
        while(list1!=nullptr && list2!=nullptr){
            int data1 = list1->val;
            int data2 = list2->val;
            if(data1 <= data2){
                dummynode->next = list1;
                list1 = list1->next;
                dummynode = dummynode->next;
            }
            else{
                dummynode->next = list2;
                list2 = list2->next;
                dummynode = dummynode->next;
            }
            //koi ek list ke sare elements aa gye h
            if(list1!=nullptr){
               dummynode->next = list1;
            }
            else if(list2!=nullptr){
                dummynode->next = list2;
            }
            
        }
        return dummyptr->next; //not include -1.
    }
};