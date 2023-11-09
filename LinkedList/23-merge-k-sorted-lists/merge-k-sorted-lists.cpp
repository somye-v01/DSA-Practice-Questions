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

class compare{
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val; //min element return kardo
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq; //min-queue
        //each list ka 1st element dalo pq me
        int n = lists.size();
        for(int i = 0; i < n; i++){
            if (lists[i]!=nullptr){
                pq.push(lists[i]);
            }
        }
    //isme se sabse min ko answer me dalo, fir uska next daldo pq me
    ListNode* head = NULL;
    ListNode* tail = NULL;
    while(!pq.empty()){
        ListNode* minel = pq.top();
        pq.pop();
        if(head == NULL){
            head = minel;
            tail = minel;
            if(tail->next != nullptr){
                pq.push(tail->next);
            }
        }   
        else{
            tail->next = minel;
            tail = minel;
            if(tail->next != nullptr){
                pq.push(tail->next);
            }
        }
    }
    return head;
    }
};