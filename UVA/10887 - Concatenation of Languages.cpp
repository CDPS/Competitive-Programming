#include <bits/stdc++.h>

using namespace std;

string a[1500];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int t, caseno = 1,n,m;
    string s;
    cin >> t;

    while(t--){
        unordered_set<string>st;
        cin >> n >> m;
        cin.ignore();

        for(int i=0;i<n;i++)
            getline(cin,a[i]);

        while(m--){
            getline(cin,s);
            for(int i=0;i<n;i++) st.insert(a[i]+s);
        }

        cout << "Case " << caseno++ << ": " << st.size() << "\n";
    }
    return 0;
}
