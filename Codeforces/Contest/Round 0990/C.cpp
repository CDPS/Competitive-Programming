#include <bits/stdc++.h>

using namespace std;

int a[2][5000];
int oo = -1000000000;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n;
    cin >> t;

    while(t--){

        cin >> n;

        for(int i=0;i<2;i++)
            for(int j=0;j<n;j++)
                cin >> a[i][j];

        int maxi = oo;
        for(int i=0;i<n;i++){
             int current = a[0][i] + a[1][i];
             for(int j=0;j<n;j++){
                if(j != i)
                    current += max(a[0][j], a[1][j]);
             }
             maxi = max(current, maxi);
        }
        cout << maxi << "\n";
    }
    return 0;
}

