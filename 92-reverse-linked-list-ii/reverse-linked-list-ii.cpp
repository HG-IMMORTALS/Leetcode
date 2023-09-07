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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
    if (l==r) {
        return head;
    }
    
    ListNode* prev=nullptr;
    ListNode* curr=head;

    for (int i=1;i<l;i++) {
        prev=curr;
        curr=curr->next;
    }

    ListNode* leftNode=prev;
    ListNode* tail=curr;

    for (int i=l;i<=r;i++) {
        ListNode* nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
    }

    if (leftNode==nullptr) {
        head=prev;
    } else {
        leftNode->next=prev;
    }
    tail->next=curr;
    return head;
}
};