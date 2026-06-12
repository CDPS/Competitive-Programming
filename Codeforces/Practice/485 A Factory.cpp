#include <bits/stdc++.h>

using namespace std;

int a, m;

bool solve(){

    cin >> a >> m;

    set<int> st;
    while( a%m != 0){

        if(st.count(a%m) )
            return false;

        st.insert(a%m);
        a += (a%m);
    }

    return true;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cout << ( solve()? "Yes" : "No" ) << "\n";
    return 0;
}
