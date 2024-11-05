#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int n,r,x;

    while(cin >> n >> r){

        vector<bool> a(n+1,0);

        for(int i=0;i<r;i++)
            cin >> x, a[x]= 1;

        bool f = true;
        for(int i=1;i<=n;i++)
            f &= a[i];

        if(!f){
            for(int i=1;i<=n;i++)
                if(!a[i]) cout << i << " ";
            cout << "\n";
        }else
            cout << "*" << "\n";
    }
    return 0;
}
