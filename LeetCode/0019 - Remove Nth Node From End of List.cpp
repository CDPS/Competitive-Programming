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
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        unordered_map<int,ListNode*> mp;
        ListNode* ans  = head;
        ListNode* curr = head;
        
        int acc =0;
        while(curr)
            mp[acc++]= curr, curr= curr->next;
        
        int toRemove = (acc-1)-(n-1);

        if(toRemove == 0)
            return ans->next;

        mp[toRemove-1]->next = mp[toRemove]->next;
        return ans;
    }
};