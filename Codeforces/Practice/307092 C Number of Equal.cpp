#include <bits/stdc++.h>

using namespace std;

const int oo = 2e9;
int a[100001];

int n,m,x;


int main(){

    cin >> n >> m;

    map<int,int> mp;
    vector<int> b;

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++){
        cin >> x;
        if(mp[x]==0)
            b.push_back(x);
        mp[x]++;
    }

    m = b.size();
    a[n] = oo;
    b.push_back(oo);

    int i = 0, j = 0;
    long long ans = 0;
    while(i <n || j <m ){
        if(a[i] < b[j]) i++;
        else if(a[i] == b[j])ans+=mp[b[j]], i++;
        else j++;
    }

    cout << ans << "\n";

    return 0;
}
