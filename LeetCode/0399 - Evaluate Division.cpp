class Solution {
public:
    
    struct node{
        string x;
        double val;
        node(string x, double val) : x(x), val(val) {}
    };
    unordered_map<string, vector<node> > g;
    
    double bfs(string source, string target){
        
        if(g.count(source) ==0 || g.count(target) == 0 )
            return -1.0;

        queue<node> q;
        unordered_set<string> visit;    
        q.push(node(source, 1.0));
        
        visit.insert(source);
        
        while(!q.empty()){
            
            node u = q.front();
            q.pop();
            
            if(u.x == target)
                return u.val;
            
            for(int i = 0; i < g[u.x].size(); i++){
                if(visit.count(g[u.x][i].x) ==0){
                    q.push(node(g[u.x][i].x, u.val * g[u.x][i].val ));
                    visit.insert(g[u.x][i].x);
                }
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, 
                                vector<double>& values, 
                                vector<vector<string>>& queries) {
        
        for(int i=0;i<equations.size();i++){
            string u = equations[i][0];
            string v = equations[i][1];

            g[u].push_back(node(v, values[i]) );
            g[v].push_back(node(u, 1.0/values[i] ) );
        }

        vector<double> ans;
        for(int i=0;i<queries.size();i++)
            ans.push_back(bfs(queries[i][0], queries[i][1]));

        return ans;
    }
};