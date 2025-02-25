#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int x;
    set<int> st;
    for(int i=1;i<=5;i++) st.insert(i);
    for(int i=0;i<4;i++) cin >> x, st.erase(x);
    cout << *(st.begin()) << "\n" ;
    return 0;
}
