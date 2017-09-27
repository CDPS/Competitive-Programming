#include <bits/stdc++.h>

using namespace std;

map<int,int> mp;
vector< pair< int ,int> > l;
vector<long long> memo;

long long dp(){

    memo = vector<long long> (l.size());
    memo[0] = 1ll*l[0].second*l[0].first;


    long long ans = memo[0];

    for(int i=1;i<l.size();i++){

        int next = i-1;
        while(next >=0){
            if(l[next].first <= l[i].first-2 ) break;
            next--;
        }
        memo[i]= 1ll*l[i].first*l[i].second;
        if(next!=-1) memo[i] = memo[i] + memo[next];
        memo[i] = max(memo[i],memo[i-1]);
    }
    return memo[l.size()-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n,x;
    cin >> n;

    for(int i=0;i<n;i++)
        cin >>x, mp[x]++;

    map<int,int>::iterator it;
    for(it=mp.begin();it!=mp.end();it++)
        l.push_back(make_pair(it->first,it->second));

    cout << dp();
    return 0;
}
