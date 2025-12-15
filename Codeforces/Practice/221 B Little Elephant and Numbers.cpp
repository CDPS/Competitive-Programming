#include <bits/stdc++.h>

using namespace std;

int n;
int a[10];

bool check(int x){
    while(x > 0){
        if(a[x%10] > 0) return true;
        x/=10;
    }
    return false;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> n;

    int m = n;
    while(m > 0)
        a[m%10]++, m/=10;

    int ans = 0;
    for(int p=1;p*p<=n;p++)
        if(n%p==0)
            ans+= check(p) + (n/p!=p && check(n/p));


    cout << ans << "\n";
}
