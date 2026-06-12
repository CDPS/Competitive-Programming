#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int t = 1, n;

int solve(){

    cin >> n;

    vector< pair<int,int> > v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i].f >> v[i].s;


    sort(v.begin(), v.end(),[&] (auto a, auto b){
        if(a.s == b.s)
            return a.f > b.f;
        return a.s > b.s;
    } );


    int ans = 0, curr = 1;
    for(int i=0;i < n;i++){
        if(curr == 0) break;
        curr--;
        ans+=v[i].f;
        curr+=v[i].s;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
