#include <bits/stdc++.h>

using namespace std;

bool a[501][501];

int main(){

    int n,m,q;

    while(cin >> n >> m >> q){

        if(n==0 && m ==0 && q==0) break;

        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++) a[i][j] = 0;

        int x1,y1, x2,y2;

        while(q--){
            cin  >> x1 >> y1 >> x2 >> y2;
            for(int i=min(x1,x2);i<=max(x1,x2);i++)
                for(int j=min(y1,y2);j<=max(y1,y2);j++)
                    a[i][j] = 1;
        }

        int res = 0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(!a[i][j]) res++;

        if(res == 0)
            cout << "There is no empty spots." <<"\n";
        else if(res == 1)
            cout << "There is one empty spot." <<"\n";
        else
            cout << "There are "<< res <<" empty spots." <<"\n";
    }
    return 0;
}
