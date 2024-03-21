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
    ListNode* reverseList(ListNode* head) {
        ListNode*  a=head;
        ListNode*  b=NULL;
        ListNode*  c=NULL;
        while(a)
        {
            c=b;
            b=a;
            a=a->next;
            b->next=c;
        }
        return b;
    }
};