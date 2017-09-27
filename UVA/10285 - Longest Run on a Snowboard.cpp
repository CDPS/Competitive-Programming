#include <bits/stdc++.h>

using namespace std;

int    g[100][100];
int memo[100][100];

int xs[4]={1,-1,0,0};
int ys[4]={0,0,1,-1};

int t,n,m,vx,vy;

string s;

bool isvalid(int x,int y){
    return x >=0 && x <n && y>=0 && y< m;
}

int dp(int x, int y){

    int ans=1,deep=0;

    if(memo[x][y]!=-1) return memo[x][y];

    for(int i=0;i<4;i++){
        vx = x + xs[i], vy = y + ys[i];
        if(isvalid(vx,vy) && g[vx][vy] < g[x][y]){
           deep = max( deep,dp(vx,vy)) ;
        }
    }
    return memo[x][y]=ans+deep;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--){

        cin >> s >> n >> m;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                cin >> g[i][j];
                memo[i][j]=-1;
            }

        int ans =0;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ans = max(ans,dp(i,j));

        cout << s << ": " << ans<< "\n";
    }
    return 0;
}
