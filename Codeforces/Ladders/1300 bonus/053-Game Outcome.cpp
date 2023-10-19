#include <bits/stdc++.h>

using namespace std;

int a[30][30];

int main(){

    int n;
    cin >>n;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> a[i][j];

    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int column = 0;
            int row = 0;
            for(int k=0;k<n;k++){
                row+= a[i][k];
                column+=a[k][j];
            }
            if(column>row) ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}

