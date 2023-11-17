#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(false); cin.tie(NULL);
    int n,r,x;
    while(cin >> n >> r){

        int a[500] = {};

        while(r--)
            for(int i=0;i<n;i++)
                cin >> x, a[i]+= x;

        int acc = 0, idx = 0;
        for(int i=0;i<n;i++){
            if(a[i] >= acc )
                acc = a[i], idx = i;
        }
        cout  << idx  + 1 << "\n";
    }
    return 0;
}
