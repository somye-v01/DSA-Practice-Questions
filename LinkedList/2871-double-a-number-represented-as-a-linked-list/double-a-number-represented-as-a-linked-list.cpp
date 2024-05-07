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

    ListNode* reverse(ListNode* head){
        if(!head) return NULL;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        ListNode* prev = NULL;
        ListNode* temp = head;
        int carry = 0;
        while(temp){
            int sum = (2*temp->val) + carry;
            // cout << "sum here: "<<sum<<endl;
            carry = sum/10;
            temp->val = sum%10;
            // sum = sum/10;
            prev = temp;
            temp = temp->next;
        }
        while(carry>0){
            int tempo = carry%10;
            cout << "carry here: "<<tempo<<endl;
            ListNode* l = new ListNode(tempo) ;
            prev->next = l;
            // temp = temp->next;
            carry = carry/10;
        }
        
        return reverse(head) ;
    }
};