#include <bits/stdc++.h>

using namespace std;

map<char, int > mp;
void add(char x){ mp[x]++; }
void del(char x){ if(--mp[x]==0) mp.erase(x); }

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n; string a; set<char> st;

    cin >> n >> a;

    for(int i=0;i<n;i++) st.insert(a[i]);

    int ans = n +1;
    for(int i=0, j = 0; j < n ; j++){
        add(a[j]);
        while(i < n && mp.size() == st.size() ){
            ans= min(ans, j-i+1);
            del(a[i++]);
        }
    }

    cout << ans  << "\n";

    return 0;
}

