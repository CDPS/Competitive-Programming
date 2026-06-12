#include <bits/stdc++.h>

using namespace std;


int t = 1;

string x;

int solve(){

    cin >> x;

    int ans = 0; bool carry = false;
    for(int i=x.size() - 1; i>=0; i--){

        if(i==0 && !carry) break;

        if(x[i] == '0' && !carry)
            ans++;
        if(x[i] == '1' &&  carry)
            ans++;
        if(x[i] == '1' && !carry)
            ans+=2, carry = true;
        if(x[i] == '0' && carry)
            ans+=2;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
