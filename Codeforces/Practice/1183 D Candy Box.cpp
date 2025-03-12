#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, x;
    cin >> t;

    while(t--){

        cin >> n;
        map<int,int> mp;
        for(int i=0;i<n;i++)
            cin >> x, mp[x]++;

        priority_queue<int> pq;

        for(auto it=mp.begin(); it!=mp.end();it++)
            pq.push(it->second);

        int ans = pq.top();
        int current = pq.top();
        pq.pop();

        while(!pq.empty() ){
            int x = pq.top(); pq.pop();
            if(x < current) current = x;
            else current--;

            if(current == 0) break;

            ans+= current;
        }

        cout << ans << "\n";
    }
    return 0;
}
