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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head) return NULL;

        unordered_set<int> st;

        ListNode* ans = new ListNode(200);
        ListNode* curr = head;
        ListNode* currAns = ans;

        while(curr->next){
            if(curr->val !=curr->next->val && !st.count(curr->val))
                currAns->next = curr, currAns = currAns->next;
            else
                st.insert(curr->val);
            curr = curr->next;
        }
        currAns->next = !st.count(curr->val)? curr : NULL;
        return ans->next;
    }
};