#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, k, x;
    cin >> t;

    while(t--){

        cin >> n >> k;

        priority_queue<int> pq;
        for(int i=0;i<n;i++)
            cin >> x, pq.push(x);

        int ans = 0, acc = 1;
        while(!pq.empty()){
            if(pq.top()*acc >= k )
                pq.pop(), ans++, acc = 1;
            else
                pq.pop(), acc++;
        }

        cout << ans << "\n";
    }
    return 0;
}
