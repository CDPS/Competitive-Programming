#include <bits/stdc++.h>

using namespace std;

int a[100000];
map<int, pair< int, pair<int,int> > > mp;

int main(){

    int n;
    cin >> n;
    int maxi = 1;
    for(int i=0;i<n;i++){
        cin >> a[i];

        if(mp.find(a[i])==mp.end()){
            mp.insert( make_pair( a[i] , make_pair( 1 , make_pair( i, i ) ) ) );
        }else{
            pair< int, pair<int,int> > x = mp[ a[i] ];
            mp[a[i]] = make_pair( x.first + 1 , make_pair( x.second.first, i ) );
            maxi = max(x.first + 1, maxi);
        }
    }

    map<int, pair< int, pair<int,int> > >::iterator it;

    int l=0,h=n-1;
    for(it=mp.begin();it!=mp.end();it++){
        if( it->second.first == maxi  && it->second.second.second  - it->second.second.first < h-l ){
            l = it->second.second.first;
            h = it->second.second.second ;
        }
    }

    cout << (l+1) << " " << (h+1) << "\n";
    return 0;
}

