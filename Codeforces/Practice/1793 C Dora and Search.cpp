#include <bits/stdc++.h>

using namespace std;

int n;
int a[200000];

void solve(){

    cin >> n;

    set<int> st;
    for(int i=0;i<n;i++)
        cin >> a[i], st.insert(a[i]);

    int i=0, j = n-1;
    while(i<j){

        if(a[i] != *(st.begin()) && a[i] != *(st.rbegin()) &&
           a[j] != *(st.begin()) && a[j] != *(st.rbegin()))
           break;

        if(a[i] == *(st.begin()) || a[i] == *(st.rbegin()))
            st.erase(a[i]), i++;
        if(a[j] == *(st.begin()) || a[j] == *(st.rbegin()))
            st.erase(a[j]), j--;
    }

    if(j<=i)
        cout << -1 << "\n";
    else
        cout << i + 1 << " " << j + 1 << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}
