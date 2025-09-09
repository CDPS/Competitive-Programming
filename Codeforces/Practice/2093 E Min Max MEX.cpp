#include <bits/stdc++.h>

using namespace std;

int a[200000];
int n, k;

bool can(int x){
    int acc = 0;
    set<int>  st;
    for(int i=0;i<n;i++){
        if(a[i] < x )
            st.insert(a[i]);
        if(st.size() == x)
            acc++, st.clear();
    }
    return acc >= k;
}

int solve(){

    cin >> n >> k;

    for(int i=0;i<n;i++) cin >> a[i];

    int l = 0, h = n, m;
    while(l<h){
        m = l + ( (h-l+1)/2 );
        if(!can(m))
             h = m-1;
        else l = m;
    }
    return l;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        cout << solve() << "\n";
    return 0;
}

