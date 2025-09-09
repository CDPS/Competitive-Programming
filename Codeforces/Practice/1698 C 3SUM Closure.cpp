#include <bits/stdc++.h>

using namespace std;

int a[200000];

bool solve(){

    int n;
    cin >> n;

    int neg=0, pos=0, zeros=0;

    vector<int> v;
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i] > 0) pos++, v.push_back(a[i]);
        if(a[i] < 0) neg++, v.push_back(a[i]);
        if(a[i] ==0) zeros++;
    }

    if(pos >2 || neg > 2) return false;

    for(int i=0;i<min(2,zeros);i++)v.push_back(0);

    int m = v.size();
    for(int i=0;i<m;i++) st.insert(v[i]);

    for(int i=0;i<m;i++)
        for(int j=i+1;j<m; j++)
            for(int k=j+1;k<m;k++)
                if(!st.count(v[i]+v[j]+v[k]))
                    return false;
    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO") << "\n";

    return 0;
}
