#include <bits/stdc++.h>

using namespace std;


int main(){
    int n,k,l,c,d,p,nl,np;

    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int drink= (k*l)/nl;
    int sl = (c*d);
    int salt= (p)/np;

    int r = min( (drink) ,min(sl, (salt) ))/n;

    cout << r << "\n";
    return 0;
}
