#include <bits/stdc++.h>

using namespace std;


long long a[46];

void calcFibo(){

    a[0]=0; a[1]=1;
    for(int i=2;i<=45;i++)
        a[i] = a[i-1] + a[i-2];
}

int main(){
    calcFibo();

    long n;
    cin >> n;

    map<int, pair< long long , long long > > mp;

    for(int i=0;a[i]<=n;i++)
        for(int j=0; a[j]<=n ;j++)
               mp[  a[j]+ a[i]  ]= make_pair(a[i],a[j]);

    int r1,r2,r3;
    bool f=0;

    for(int i=0; a[i]<=n;i++){
        if( mp.count(n-a[i])>0){
            r1 = mp[ n-a[i]].first;
            r2 = mp[ n-a[i]].second;
            r3 = a[i];
            f=1;
            break;
        }
    }

    if(f)cout << r1 << " " << r2 << " " << r3 << "\n";
    else cout << "I'm too stupid to solve this problem\n";
    return 0;
}
