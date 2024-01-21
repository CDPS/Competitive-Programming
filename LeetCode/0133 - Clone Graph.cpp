/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* cloneGraph(Node* node) {
        
        if(!node)
            return node;
            
        Node* ans = new Node(node->val);
        
        queue<Node*> q;
        q.push(node);
        
        unordered_map<int,Node*> mp;
        mp[ans->val] = ans;

        while(!q.empty()){

            Node* u = q.front();
            q.pop();

            for(int i=0;i< u->neighbors.size();i++){             
                if(!mp.count(u->neighbors[i]->val)){
                    mp[u->neighbors[i]->val] = new Node(u->neighbors[i]->val) ;
                    q.push(u->neighbors[i]);
                }
                mp[u->val]->neighbors.push_back(mp[u->neighbors[i]->val]);
            }    
        }

        return ans;
    }
};