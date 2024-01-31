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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* ans  = head;
        ListNode* first = head;
        
        for(int i=1;i<left-1;i++)
            first = first->next;
        stack<ListNode*> st;
        
        ListNode* last = left==1? first: first->next;
        
        for(int i= left;i<=right && last;i++)
            st.push(new ListNode(last->val)), last = last->next;
        
        if(left==1){
            ans = st.top(); st.pop();
            first = ans;
        }
        while(!st.empty()){
            first->next = st.top(); st.pop();
            first = first->next;
        }

        first->next = last;
        return ans;
    }
};