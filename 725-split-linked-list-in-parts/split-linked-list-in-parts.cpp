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
    // int nodecount(ListNode *head)
    // {
    //     int c=0;
    //     while(head)
    //     {
    //         ++c;
    //         head=head->next;
    //     }
    //     return c;
    // }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int l=0;
        ListNode *curr=head;
        vector<ListNode*>parts;
        while(curr)
        {
            l++;
            curr=curr->next;
        }
        int base_size=l/k,extra=l%k;
        curr=head;
        for(int i=0;i<k;i++)
        {
            int part_size=base_size+(extra>0);
            ListNode* part_head=NULL, *part_tail=NULL;
            for(int j=0;j<part_size;j++)
            {
                if(!part_head)
                {
                    part_head=part_tail=curr;
                }
                else
                {
                    part_tail->next=curr;
                    part_tail=part_tail->next;
                }
                if(curr)
                {
                    curr=curr->next;
                }
            }
            if(part_tail)
                {
                    part_tail->next=NULL;
                }
            parts.push_back(part_head);
            extra=max(extra-1,0);
        }
        return parts;
    }
};