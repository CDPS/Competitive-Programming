#include <bits/stdc++.h>

using namespace std;

int t, n, m, x;

bool solve(){

    cin >> n  >> m;

    priority_queue<int> a, b;

    for(int i=0; i< n; i++) cin >> x, a.push(x);
    for(int i=0; i< m; i++) cin >> x, b.push(x);

    bool turn = 0;
    while(true){

        if(a.empty()) return false;
        if(b.empty()) return true;

        if(!turn){
            if( a.top() < b.top() )
                b.push( b.top() - a.top());
            b.pop();
        }
        else{
            if( b.top() < a.top() )
                a.push( a.top() - b.top());
            a.pop();
        }
        turn^=1;
    }

    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "Alice" : "Bob") << "\n";

    return 0;
}
