#include <bits/stdc++.h>

using namespace std;

int n;
int a[500000];

int solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a, a + n );

    int curr = 0;
    for(int i= n/2; i < n; i++){
        if(curr < n/2 && a[curr]*2 <= a[i])
            curr++;
    }

    return n - curr;
}

int main(){


    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}
