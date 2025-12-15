#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[200000];

int solve(){

    cin >> n;

    for(int i=0;i<n;i++) cin >> a[i];

    set<int> prev, curr;

    prev.insert(a[0]);

    int ans = 1;
    for(int i=1;i<n;i++){

        curr.insert(a[i]);

        if(prev.count(a[i]))
            prev.erase(a[i]);

        if(prev.size()==0)
            ans++, prev = curr, curr.clear();
    }

    return ans;
}


int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}

