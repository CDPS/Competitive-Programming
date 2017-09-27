#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,x;
    cin >> n >> x;

    map<int, vector< pair<int,pair<int,int> > >  > mp;

    int l,h,c;

    for(int i=0;i<n/2;i++){
        cin >> l >> h >> c;
        mp[ h-l+1] = make_pair(l,make_pair(h,c));
    }

    map< int, pair<int,pair<int,int> > >::iterator it;

    for(int i=n/2;i<n;i++){
        cin >> l >> h >> c;
        mp[x-l-h+1]
    }
    return 0;
}
