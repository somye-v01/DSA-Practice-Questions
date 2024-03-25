/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>m;
        Node* hd = head;
        while(hd){
            m[hd]= new Node(hd->val);
            hd=hd->next;
        }
        hd = head;
        while(hd){
            m[hd]->next=m[hd->next];
            m[hd]->random = m[hd->random];
            hd=hd->next;
        }
        return m[head];
    }
};