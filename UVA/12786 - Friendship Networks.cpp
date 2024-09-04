#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n,x;
    while(cin >> n){

        priority_queue<int> pq, aux;

        for(int i=0;i<n;i++){
            cin >> x;
            pq.push(x);
        }

        bool ans = 1;
        while(!pq.empty()){

            int u = pq.top(); pq.pop();

            if(u > pq.size()){ ans = false;  break; }

            while(!pq.empty()){
                int v = pq.top(); pq.pop();
                v = (u-- >  0 )? v-1 : v;
                if(v > 0) aux.push(v);
            }
            pq = aux;
            aux = priority_queue <int>();
        }

        cout << ans << "\n";
    }

    return 0;
}
