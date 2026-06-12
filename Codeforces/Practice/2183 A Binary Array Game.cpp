#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[300];

bool solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    bool all_ones   = true;
    for(int i=0;i<n;i++)
         all_ones &= (a[i]==1);

    if(all_ones)
        return true;

    if(a[0]== 1 || a[n-1] == 1)
        return true;

    return false;
}


int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "Alice" : "Bob") << "\n" ;

    return 0;
}
