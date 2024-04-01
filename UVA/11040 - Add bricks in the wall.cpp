#include <bits/stdc++.h>

using namespace std;

int g[9][9];

int main(){

    int n,x;
    cin >> n;

    while(n--){

        for(int i=0, k=0;i<5;i++,k+=2)
            for(int j=0, l=0;j<=i;j++,l+=2)
                cin >> g[k][l];

        for(int i=1;i<=7;i+=2)
            g[8][i] = (g[6][i-1] - (g[8][i-1] + g[8][i+1]) )/2;

        for(int i=7;i>=0;i--)
            for(int j=0;j<i+1;j++)
                g[i][j] = g[i+1][j] + g[i+1][j+1];

        for(int i=0;i<9;i++){
            for(int j=0;j<=i;j++){
                if(j>0) cout << " ";
                cout << g[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}
