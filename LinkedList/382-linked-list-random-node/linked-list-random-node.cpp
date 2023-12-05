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
    private:
        ListNode* head;
public:

    // int getLength(ListNode* head){
    //     int count = 0;
    //     ListNode* curr = head;
    //     while(curr!=NULL){
    //         count++;
    //         curr = curr->next;
    //     }
    //     return count;
    // }

    Solution(ListNode* head) {
       this->head = head;

    }
    
    int getRandom() {
        int count = 0;
        ListNode* curr = head;
        vector<int> v;
        while(curr!=NULL){
            count++;
            v.push_back(curr->val);
            curr = curr->next;
        }
        int index = rand() % count;
        return v[index];
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */