#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n,k,x;
    cin >> t;

    while(t--){

        cin >> n >> k;

        map<int,int> mp;
        for(int i=0;i<n;i++)
            cin >> x, mp[x]++;


        vector<int> v;
        for(auto it=mp.begin();it!=mp.end();it++)
                v.push_back(it->second);
        sort(v.begin(), v.end());

        int i=0;
        while(i < v.size() && k >= v[i]){
            if(v[i]<= k ){
                k-= v[i];
            }
            i++;
        }

        int ans = v.size()-i;

        cout << (ans==0? 1 : ans ) << "\n";
    }

    return 0;
}
