#include <bits/stdc++.h>

using namespace std;

int n,m;
int  g[100][100];

void acc(int x, int y){
    for(int i=x-1; i<=x+1;i++)
        for(int j=y-1;j<=y+1;j++)
            if( (i >=0 && i< n && j>=0 && j<m )&& g[i][j]!=-1)
                g[i][j]++;
}

int main(){
    char c;
    int caseno =1,first=1;


    while( (cin >> n >> m) && n &&  m ){

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    cin >> c ;
                    g[i][j]= (c=='*')? -1 : 0;
            }
        }

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(g[i][j]==-1)
                    acc(i,j);
        if(!first) cout << "\n";
        first=0;
        cout << "Field #"<< caseno++ <<":\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==-1)cout << '*';
                else cout << g[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}
