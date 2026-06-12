#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[10];

bool sorted(){
    for(int i=1; i < n; i++)
        if(a[i] < a[i-1])
            return false;
    return true;
}

int solve(){

    cin >> n;

    for(int i =0; i< n;i++) cin >> a[i];

    if(sorted())
        return n;

    return 1;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
