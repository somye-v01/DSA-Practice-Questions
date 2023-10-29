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

    // int gcd(int a ,int b){
    //     int ans = 1;
    //     if(a%b == 0){
    //         return b;
    //     }
    //     else if(b%a == 0){
    //         return a;
    //     }
        
    //     else{
    //         int mini = 0;
    //         mini = (a>b) ? b: a;
    //         for(int i = 1; i < mini; i++){
    //             if(a%i==0 && b%i==0){
    //                 ans = i;
    //             }
    //         }
    //     }
    //     return ans;
    // }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        while( temp != NULL && temp->next!=NULL){
            ListNode* temp1 = temp->next;
            int gcd1 = gcd(temp->val,temp1->val);
            ListNode* newadd = new ListNode(gcd1);
            temp->next = newadd;
            newadd->next = temp1;
            temp = newadd->next;
        }
        return head;
    }
};