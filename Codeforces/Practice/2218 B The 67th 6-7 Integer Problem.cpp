#include <bits/stdc++.h>

using namespace std;

int t , n;
int a[7];

int solve(){

    for(int i=0; i< 7; i++) cin >>a[i];

    sort(a , a + 7);

    int ans = 0;
    for(int i =0; i < 6; i++)
        ans+= (a[i]*-1);

    return ans + a[6];
}


int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
