#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, x;
    cin >> t;

    while(t--){

        cin >> n;
        priority_queue<int, vector<int>, greater<int> > pq;

        while(n--)
            cin >> x, pq.push(x);

        while(pq.size() > 1){
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            pq.push(a+b-1);
        }

        cout << pq.top() << "\n";
    }
    return 0;
}
