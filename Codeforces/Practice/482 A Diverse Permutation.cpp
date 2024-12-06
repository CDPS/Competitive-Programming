#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, k;
    cin >> n >> k;

    if(k == 1){
        cout << 1;
        for(int i=2;i<=n;i++)
            cout << " " << i;
        cout << "\n";
        return 0;
    }

    int m = k-1;
    int maxi = n, mini = 1, f = 0;
    cout << maxi--;
    while(m--){
        cout << " " << ( (f)? maxi-- : mini++);
        f = !f;
    }

    if(k%2){
        for(int i= maxi; i>=mini;i--)
            cout << " " << i;
    }
    else{
        for(int i= mini;i <= maxi;i++)
            cout << " " << i;
    }

    cout << "\n";
    return 0;
}
