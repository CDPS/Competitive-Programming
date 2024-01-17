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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        
        ListNode* ans = new ListNode();
        ListNode* curr = ans;
        while(a || b){

            int val1 = (a)? a->val : 200;
            int val2 = (b)? b->val : 200;
            ListNode* temp;
            if(val1 <= val2){
                temp = new ListNode(val1);
                a = a->next;
            }else{
                temp = new ListNode(val2);
                b = b->next;
            }
            curr->next = temp;
            curr = curr->next;
        }
        return ans->next;
    }
};