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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* ref = new ListNode(0) ;
        ListNode* ans = ref;
        while(t1->next && t2->next){
            t1 = t1->next;
            t2 = t2->next;
        }
        if(t1->next){
            while(t1->next){
                t1=t1->next;
                ListNode* temp = new ListNode(0);
                t2->next=temp;
                t2=t2->next;
            }
        }
        if(t2->next){
            while(t2->next){
                t2=t2->next;
                ListNode* temp = new ListNode(0);
                t1->next=temp;
                t1=t1->next;
            }
        }
        //printing l1 to see sab sahi or not
        // while(l2){
        //     cout<<l2->val<<endl;
        //     l2=l2->next;
        // }
        //abhi dono number me same digits hai
        int carry = 0;
        while(l1){
            int num1 = l1->val;
            int num2 = l2->val;
            int sum = num1+num2+carry;
            // cout<<"val of num1 is: "<<num1<<" & num2 val is: "<<num2<<" and carry: "<<carry<<endl;
            carry = sum/10;
            ListNode* tempst = new ListNode(sum%10);
            ans->next = tempst;
            ans=ans->next;
            l1=l1->next;
            l2=l2->next;
        }
        if(carry){
            ListNode* tempst = new ListNode(carry);
            ans->next = tempst;
            // ans=ans->next;
        }
        return ref->next;
    }
};