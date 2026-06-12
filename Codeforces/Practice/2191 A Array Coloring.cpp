#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[100];

bool check(bool curr){

    vector<pair<int,bool>> v(n);
    for(int i=0; i < n;i++)
        v[i]  ={a[i], curr }, curr= !curr;

    sort(v.begin(), v.end());

    for(int i=1;i<n;i++)
        if(v[i].second==v[i-1].second)
            return false;

    return true;
}

bool solve(){

    cin >> n;
    for(int i=0;i<n; i++)
        cin >> a[i];

    return check(1);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << ( solve()? "YES" : "NO") << "\n";

    return 0;
}



