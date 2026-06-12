#include <bits/stdc++.h>

using namespace std;

int n, k, x;
int solve(){

    cin >> n >> k;

    deque<int> v;

    bool check = false;
    for(int i=0;i<n;i++){
        cin >> x, v.push_back(x);
        if(x == k)
            check = true;
    }

    int ans = 0;
    if(!check)
        ans++, v.push_back(k);

    sort(v.begin(), v.end());

    int median =  v[ v.size()/2 - (v.size()%2==0) ];
    while( median !=  k){
        if(median <= k )
            v.push_back(1);
        else
            v.push_front(1);
        ans++;
        median =  v[ v.size()/2 - (v.size()%2==0) ];
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}
