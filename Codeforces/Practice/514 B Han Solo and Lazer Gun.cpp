#include <bits/stdc++.h>

using namespace std;

int t = 1, n, xO, yO, xi, yi;

int solve(){

    cin >> n >> xO >> yO;

    set< pair<int,int> > st;
    for(int i=0; i < n ; i++){
        cin >> xi >> yi;

        int dx = xi - xO;
        int dy = yi - yO;

        int d = __gcd(abs(dx), abs(dy));

        st.insert({abs(dx/ d ), abs(dy/ d )});
    }

    return st.size();
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
