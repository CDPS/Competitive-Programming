#include <bits/stdc++.h>

using namespace std;

int t, n , m, val;

struct node{
    int x, y;
    node(int x, int y): x(x), y(y){}
    bool operator < (const node &a) const {
        if (x == a.x)
            return y < a.y;
        return x > a.x;
    }
};

int solve(){

    cin >> n >> m;

    multiset<int> st;
    for(int i=0; i <n ; i++)
        cin >> val, st.insert(val);

    vector< pair<int,int> > b(m);
    for(int i = 0; i < m; i++) cin >> b[i].first;
    for(int i = 0; i < m; i++) cin >> b[i].second;

    priority_queue<int , vector<int>, greater<int> > zeroes;
    priority_queue<node> not_zeroes;
    for(int i=0; i < m; i++){
        if(b[i].second == 0) zeroes.push(b[i].first);
        else not_zeroes.push(node( b[i].first, b[i].second ));
    }

    int ans = 0;
    while( !not_zeroes.empty() && !st.empty() ){

        auto m = not_zeroes.top();
        auto it = st.lower_bound(m.x);

        if(it == st.end()){
            break;
        }

        ans++;
        int x = *it;
        st.erase(it);
        not_zeroes.pop();
        st.insert(max(x, m.y));
    }

    while( !zeroes.empty() && !st.empty() ){

        int y = zeroes.top();

        auto it = st.lower_bound(y);

        if(it == st.end()){
            break;
        }

        ans++;
        st.erase(it);
        zeroes.pop();
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
