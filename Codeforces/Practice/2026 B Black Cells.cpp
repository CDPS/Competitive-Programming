#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
ll a[2000];

bool f(ll x){

    int skips = n%2;

    set<int> st;
    for(int i=0;i<n;i++)st.insert(i);

    for(int i=1;i<n;i+=2){
        if(a[i]-a[i-1] > x && !skips )return false;
        if(a[i]-a[i-1] > x){
            skips--; st.erase(--i); continue;
        }
        st.erase(i); st.erase(i-1);
    }

    if(n%2==0) return st.size() == 0;
    if(skips ==0) return st.size() == 0;
    return st.size() == 1;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--){

        cin >> n;
        for(int i=0;i<n;i++) cin >> a[i];

        ll l = 1, h= 1e18, m;
        while(l< h){
            m = l + ( (h-l)/2 );
            if(f(m)) h = m;
            else l = m + 1;
        }

        cout << l << "\n";
    }
    return 0;
}
