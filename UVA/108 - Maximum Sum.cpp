#include <bits/stdc++.h>

using namespace std;

int m[101][101];


int getMax(int n){
    int maxi=-100000000;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=i;k<=n;k++)
                for(int l=j;l<=n;l++)
                    maxi= max(maxi, m[k][l] - m[i-1][l] - m[k][j-1] + m[i-1][j-1]);
    return maxi;
}

int main(){
    cin.sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> m[i][j], m[i][j]+= m[i-1][j] + m[i][j-1]-m[i-1][j-1];
    cout << getMax(n) << "\n";
    return 0;
}
