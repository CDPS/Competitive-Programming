#include <bits/stdc++.h>

using namespace std;

int a[200000];
int b[200000];


pair<int,int> f(int ai, int bi){

    if(bi == 0) return {0,0};
    else if(ai >0 && bi > 0) bi*=-1;
    else if(ai >0 && bi < 0) bi*=-1;
    else if(ai <0 && bi > 0) ai*=-1;
    else if(ai <0 && bi < 0) ai*=-1;

    int d = __gcd(abs(ai), abs(bi));
    return {bi/d, ai/d};
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n;

    cin >> n;

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];


    int ans1 = 0 , ans2 = 0;

    map<pair<int,int>, int> mp;
    for(int i=0;i<n;i++){

        if(a[i] ==0 && b[i] !=0){continue;}
        if(a[i] == 0 && b[i]==0){ans2++; continue;}

        ans1 = max(ans1, ++mp[ f( a[i], b[i] ) ]);
    }

    cout << ans1 +  ans2 << "\n";

    return 0;
}
