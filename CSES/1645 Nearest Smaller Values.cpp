#include <bits/stdc++.h>

using namespace std;

int a[200000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n;

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    stack<int> st;
    for(int i=0;i<n;i++){

        while(!st.empty() && a[st.top()] >= a[i])
            st.pop();

        cout << ( st.empty() ?0 : st.top() + 1 ) << " ";

        st.push(i);
    }

    cout << "\n";

    return 0;
}
