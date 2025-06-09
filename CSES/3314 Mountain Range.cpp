#include <bits/stdc++.h>

using namespace std;

int a[200000];
int l[200001];
int r[200001];
int oo = 1e9;

int main(){

    int n;
    cin >> n;

    for(int i=n-1;i>=0;i--) cin >> a[i];

    stack<pair<int, int> > st; st.push({a[0], 0})

    for(int i=0;i<n;i++){
        if(a[i]> st.top().first)
            st.push(a[i], i);
        l[i] = st.top().second;
    }

    st.clear();

    st.push({a[n-1], n-1});
    for(int i=n-1;i>=0;i--){
        if(a[i]> st.top().first)
            st.push(a[i], i);
        r[i] = st.top().second;
    }



    return 0;
}
