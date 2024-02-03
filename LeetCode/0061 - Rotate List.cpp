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
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head)
            return NULL;
               
        ListNode* curr = head;
        unordered_map<int,ListNode*> mp;
        int n =0;
        while(curr)
            n++, curr = curr->next;
        
        curr = head;
        int i = 0;
        while(curr)
            mp[ ((i%n)+ (k%n) )%n ] = curr, curr = curr->next, i++; 

        for(i=0;i<n-1;i++)
            mp[i]->next = mp[i+1];
        mp[i]->next = NULL;

        return mp[0];
    }
};