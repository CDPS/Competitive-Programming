/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    Node* copyRandomList(Node* head) {
        
        unordered_map<Node*, Node*> mp;
        Node* curr = head;
        
        while(curr)
            mp[curr] = new Node(curr->val), curr = curr->next;
        
        curr = head;
        while(curr){
            Node* aux   = mp[curr];
            aux->next   = mp[curr->next];
            aux->random = mp[curr->random];
            curr = curr->next;
        }

        return mp[head];
    }
};