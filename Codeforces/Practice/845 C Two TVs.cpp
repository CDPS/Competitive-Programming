#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

pair<int,int> a[200000];

int main(){

    int n, l, r;

    cin >> n;

    for(int i=0;i<n;i++)
        cin  >> l >> r, a[i] = {l,r};

    sort(a, a + n);

    stack<pair<int,int>> q1, q2;

    q1.push({-1,-1}); q2.push({-1,-1});
    for(int i=0;i<n;i++){
        if( a[i].f > q1.top().s){
            q1.push(a[i]); continue;
        }
        if( a[i].f > q2.top().s){
            q2.push(a[i]); continue;
        }
    }

    cout << ( (q1.size()-1) + (q2.size()-1) == n? "YES" : "NO" ) << "\n";
    return 0;
}
