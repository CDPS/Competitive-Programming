/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(root == NULL) 
            return root;

        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            
            vector<Node *> v;
            while(!q.empty())
                v.push_back( q.front()), q.pop();
            
            for(int i=1;i<v.size();i++)
                v[i-1]->next = v[i];
            v[v.size()-1]->next= NULL;

            for(int i=0;i<v.size();i++){
                if(v[i]->left)  q.push(v[i]->left);
                if(v[i]->right) q.push(v[i]->right);
            }
        }

        return root;
    }
};