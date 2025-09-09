#include <bits/stdc++.h>

using namespace std;

struct node{
    int i, l;
    node(int i, int l): i(i), l(l){}
};

bool v[1000][1000];
int n; string s;

bool bfs(){

    queue<node> q;
    q.push(node(0, n-1));

    while(!q.empty()){

        node u = q.front(); q.pop();
        int i = u.i; int l = u.l;

        if(i == l && (s[i]== 'A'||s[i]== 'T'))
            return true;

        if(s[i] == 'A'&& !v[i+1][l]) q.push(node(i+1,l)), v[i+1][l]=1;

    }
    return false;
}

void solve(){
    memset(v, 0, sizeof v);
    if(n == 1)
        cout << ( (s[0]== 'A'||s[0]== 'T')? "simple" : "doomed" ) << "\n";
    else
         cout << ( bfs()? "mutation" : "doomed" ) << "\n";
}

int main(){

    while(cin >> n >> s) solve();
    return 0;
}
