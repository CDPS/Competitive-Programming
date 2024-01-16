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

        int carry = 0;
        ListNode* ans = new ListNode();
        ListNode* curr = ans;

        while(l1 || l2 || carry){

            int val1 = (l1)? l1->val : 0;
            int val2 = (l2)? l2->val : 0;
            int sum = val1+ val2 + carry;
            
            ListNode* temp = new ListNode( sum%10 );

            carry = sum/10;

            l1 = (l1)? l1->next : NULL;
            l2 = (l2)? l2->next : NULL;
            curr->next = temp;
            curr = curr->next;
        }

        return ans->next;
    }
};