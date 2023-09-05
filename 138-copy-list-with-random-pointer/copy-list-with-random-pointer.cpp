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
        if(!head) return NULL;
        unordered_map<Node*,Node*>purne_se_naya;
        Node* abhi=head;
        while(abhi)
        {
            purne_se_naya[abhi]=new Node(abhi->val);
            abhi=abhi->next;
        }
        abhi=head;
        while(abhi)
        {
            purne_se_naya[abhi]->next=purne_se_naya[abhi->next];
            purne_se_naya[abhi]->random=purne_se_naya[abhi->random];
            abhi=abhi->next;
        }
        return purne_se_naya[head];
    }
};