class Solution {
public:

    struct hashFunction { 
        size_t operator()(const pair<int,int> &x) const { 
            return x.first ^ x.second; 
        } 
    };

    struct node {
        int i, j, x;
        node(int i,int j, int x) : i(i), j(j), x(x){ }
        bool operator < (const node &a) const{
            return a.x  < x ;
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        
        int n= a.size(), m =b.size();
        
        vector<vector<int>> ans;
        priority_queue<node> pq;
        unordered_set<pair<int, int>,hashFunction> st;

        pq.push(node(0,0, a[0] + b[0]));
        st.insert(make_pair(0,0)) ;

        while(k--){
            node u = pq.top();
            pq.pop();

            ans.push_back({a[u.i], b[u.j]});

            int next_j = (u.j == m-1)? u.j : u.j + 1;
            int next_i = (u.i == n-1) ? u.i : u.i + 1;
            
            if(!st.count(make_pair(u.i,next_j)))
                pq.push(node(u.i, next_j, a[u.i] + b[next_j])), st.insert(make_pair(u.i,next_j));
            if(!st.count(make_pair(next_i, u.j)))  
                pq.push(node(next_i, u.j, a[next_i] + b[u.j])), st.insert(make_pair(next_i, u.j));
        }

        return ans;
    }
};