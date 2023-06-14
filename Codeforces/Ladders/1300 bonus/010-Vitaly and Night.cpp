#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m,x,y;
    cin >> n >> m;

    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> x >> y;
             res+= x|y;
        }
    }

    cout << res << "\n";
    return 0;
}
