#include <bits/stdc++.h>

using namespace std;

int a[400001];
int t, n, l, r;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cin >> t;

    while(t--){

        cin >> n;
        vector<pair<int,int>> v;
        map<int, int> mp;

        for(int i=1;i<=2*n;i++)
            a[i]= 0;

        for(int i=0;i<n;i++){
            cin >> l >> r;
            if(l == r) a[l] = 1, mp[l]++;
            v.push_back({l,r});
        }

        for(int i=1;i<=2*n;i++)
            a[i]= a[i] + a[i-1];

        for(int i=0;i<n;i++){
            l = v[i].first, r= v[i].second;
            if(l==r){ cout << (  mp[l]>1? 0 : 1 ); continue; }
            cout << ( a[r]-a[l-1] ==  r-l+1? 0 : 1 );
        }
        cout << "\n";
    }
    return 0;
}

