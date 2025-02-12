#include <bits/stdc++.h>

using namespace std;

int t,n;
int a[200000];

bool solve(){
    set<long long> mp; mp.insert(0);
    long long sum = 0;
    for(int i=0;i<n;i++){
        sum += a[i];
        if(mp.count(sum)) return true;
        mp.insert(sum);
    }
    return false;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--){

        cin >> n;
        for(int i=0;i<n;i++)
            cin >> a[i], a[i]=(i%2)? a[i]*-1 : a[i];

        cout << (solve()? "YES" : "NO") << "\n";
    }
    return 0;
}
