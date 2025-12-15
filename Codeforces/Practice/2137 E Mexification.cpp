#include <bits/stdc++.h>

using namespace std;

int t, n, k;

vector<int> getMex(vector<int> &a){

    set<int> st;
    for(int i=0;i<n;i++) st.insert(i);

    map<int,int> mp;
    for(int i=0;i<n;i++){
        if(++mp[a[i]]==1)
            st.erase(a[i]);
    }

    vector<int> mex(n);
    for(int i=0;i<n;i++){
        if(--mp[a[i]] == 0)
            st.insert(a[i]);
        mex[i] = *(st.begin());
        if(++mp[a[i]]==1)
            st.erase(a[i]);
    }
    return mex;
}

long long solve(){

    cin >> n >> k;

    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];

    vector< vector<int> > mex(4);

    mex[0] = getMex(a);
    mex[1] = getMex(mex[0]);
    mex[2] = getMex(mex[1]);
    mex[3] = getMex(mex[2]);

    int mexIndex = (k > 2 )?  2 + (k-1)%2 : k - 1;
    long long ans = 0;
    for(int i=0;i<n;i++)
        ans+= mex[mexIndex][i];

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}

