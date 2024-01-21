class Solution {
public:

    struct node{
        int x;
        int cost;
        node(int x, int cost) : x(x), cost(cost) {}
    };

    bool visit[400];

    void getCoordinates(int n,int pos, int &x, int &y){
         x = n-1 - pos/n; 
         y = (pos/n)%2==0? pos%n : n-1-(pos%n);
    }

    int bfs(int source, int target, int n,vector<vector<int>>& g){
        
        if(g[0][0]!=-1) return -1;

        queue<node> q;
        q.push(node(source, 0));
        visit[source] = true;

        while(!q.empty()){

            node u = q.front();
            q.pop();
            
            if( u.x == target )
                return u.cost;

            for(int i= u.x +1; i <= u.x + 6 && i <= target; i++){
                int x,y;
                getCoordinates(n, i, x,y);
                int v = (g[x][y]!=-1)? g[x][y]-1 : i;
                if(!visit[v])
                    q.push(node(v,u.cost+1)), visit[v]=true;
            }
        }
        return -1;
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        return bfs(0, (n*n)-1, n, board);;
    }
};