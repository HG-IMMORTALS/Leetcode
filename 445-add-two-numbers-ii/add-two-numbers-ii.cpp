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
      	stack<int> stackA;
        stack<int> stackB;
        
		while (l1) {
			stackA.push(l1->val);
			l1 = l1->next;
		}
        
		while (l2) {
			stackB.push(l2->val);
			l2 = l2->next;
		}

		ListNode* Temp = new ListNode(0); // Create anchor node. The list will be built attached to this node.
		Temp->next = nullptr;
		int carry{}, num1{} ,num2{};

		while (!stackA.empty() || !stackB.empty() || carry) { // The trick is that carry is needed in the while look.
		// As long as you have a remainder, you need a node to hold that remainder. This is what frustrated me
		// for quite some time...
			
            if (!stackA.empty()) {
				num1 = stackA.top();
				stackA.pop();
			}
            

			if (!stackB.empty()) {
				num2 = stackB.top();
				stackB.pop();
			}

			int sum = num1 + num2 + carry;
			int value = sum % 10;
			carry = sum / 10; // e.g. 11 / 10 is 1
            
            num1 = 0; // Reset num1 and num2
            num2 = 0;
            
			ListNode* newNode = new ListNode(value);
			newNode->next = Temp->next; // Building on the original temp anchor
			Temp->next = newNode;
        }
        return Temp->next; // The attached list starts after the anchor node.
    }
        // stack<int>A;
        // stack<int>B;
        // while(l1)
        // {
        //     A.push(l1->val);
        //     l1=l1->next;
        // }
        // while(l2)
        // {
        //     B.push(l2->val);
        //     l2=l2->next;
        // }
        // ListNode* Temp=new ListNode(0);
        // Temp->next=nullptr;
        // int carry{},num1{},num2{};
        // while(!A.empty()||!B.empty()||carry)
        // {
        //     if(!A.empty())
        //     {
        //         num1=A.top();
        //         A.pop();
        //     }
        //     if(!B.empty())
        //     {
        //         num1=B.top();
        //         B.pop();
        //     }
        //     int sum=num1+num2+carry;
        //     int value=sum%10;
        //     carry=sum/10;

        //     num1=0;
        //     num2=0;
        //     ListNode* newNode=new ListNode(value);
        //     newNode->next=Temp->next;
        //     Temp->next=newNode;
        // }
        // return Temp->next;
    // }
};