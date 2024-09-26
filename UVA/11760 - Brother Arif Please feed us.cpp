#include <bits/stdc++.h>

using namespace std;

bool c[10000], r[10000];
int xs[5] = {0,1,-1,0,0};
int ys[5] = {0,0,0,1,-1};

int n, m;

bool isvalid(int x, int y){
    return x >=0 && x <n && y>=0 && y <m && !r[x] && !c[y];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int caseno = 1,q,x,y;

    while(cin >> n >> m >> q){

        if(n == 0 && m == 0 && q==0) break;

        for(int i=0;i<max(n,m);i++)
            c[i] = r[i] = 0;

        while(q--)
            cin >> x >> y, r[x] = c[y] = 1;
        cin >> x >> y;

        bool ans = false;
        for(int i=0;i<5;i++){
            int vx = xs[i] + x;
            int vy = ys[i] + y;
            ans|=isvalid(vx,vy);
        }

        if(ans)
            cout<< "Case "<< caseno++ << ": Escaped again! More 2D grid problems!" << "\n";
        else
            cout<< "Case "<< caseno++ << ": Party time! Let's find a restaurant!" << "\n";
    }
    return 0;
}
