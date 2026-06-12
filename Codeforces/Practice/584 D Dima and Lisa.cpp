#include <bits/stdc++.h>

using namespace std;

int t= 1, n;

bool isprime(int x){

    if(x==2) return true;
    if(x%2 == 0) return false;

    for(int i=3; i*i <=x; i+=2)
        if(x%i == 0)
            return false;
    return true;
}


void solve(){

    cin >> n;

    if(isprime(n)){
        cout << 1 << "\n" << n << "\n";
        return;
    }

    if(isprime(n-2)){
        cout << 2 << "\n" << 2 << " " << n-2 << "\n";
        return ;
    }

    int np = n - 3;
    for(int i=3; i <=np; i++)
        if(isprime(i) && isprime(np-i)){
            cout << 3 << "\n" <<  3 << " " << i << " " << np-i << "\n";
            break;
        }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
