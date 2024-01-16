/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *current) {
        if(!current)
            return false;
            
        for(int i=0;i<10002;i++){
            if(!current->next)
                return false;
            current = current->next;
        }
        return true;
    }
};