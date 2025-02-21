#include <bits/stdc++.h>

using namespace std;

int a[200002];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, x;
    cin >> t;

    while(t--){
        cin >> n;

        stack<int> q1,q2; q1.push(2e9); q2.push(2e9);

        int ans = 0;
        while(n--){
            cin >> x;
            if(x <= q1.top() && x<= q2.top()){
                if(q1.top()> q2.top()) q2.push(x);
                else q1.push(x);
                continue;
            }

            if(x >  q1.top() && x > q2.top()){
                if(q1.top()> q2.top()) q2.push(x);
                else q1.push(x);
                ans++;
                continue;
            }

            if(x <= q1.top()){ q1.push(x); continue; }
            if(x <= q2.top()){ q2.push(x); continue; }

            if(q1.top() < q2.top()) q1.push(x);
            else q2.push(x);
             ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}

