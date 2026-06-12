#include <bits/stdc++.h>

using namespace std;

int t = 1, n, m, start, finish;

struct node {
    int t;
    int l;
    int r;
};

void solve(){

    cin >> n >> m >> start >> finish;

    vector<node> v(m);
    for(int i=0 ; i <m ; i++)
        cin >> v[i].t >> v[i].l >> v[i].r;

    char op = finish > start? 'R' : 'L';
    int dir =  finish > start? 1 :  -1;

    int idx = 0, time= 1;
    while(start != finish){

        if(idx < m && v[idx].t == time){
            if( (start >= v[idx].l && start <= v[idx].r) ||
                (start + dir >= v[idx].l && start + dir <= v[idx].r) ){
                cout << 'X';
            } else {
                cout << op;
                start += dir;
            }
            idx++;

        } else {
            cout << op;
            start += dir;
        }

        time++;
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
