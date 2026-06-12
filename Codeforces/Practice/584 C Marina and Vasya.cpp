#include <bits/stdc++.h>

using namespace std;

int t = 1, n, x;

string a, b, c;


char get(char ai, char bi){
    if (ai != 'a' && bi != 'a') return 'a';
    if (ai != 'b' && bi != 'b') return 'b';
    return 'c';
}

void solve(){

    cin >> n >> x >> a >> b;

    int diff = 0, eq = 0;
    for(int i=0; i < n ; i++)
        diff += (a[i] != b[i]), eq+=(a[i] == b[i]);

    int keep = n-x;
    if( keep >  (diff/2) +  eq){
        cout << -1 << "\n";
        return;
    }

    int use_eq = min(keep, eq);
    int use_diff = keep - use_eq;

    int a_curr = 0, b_curr = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == b[i]){
            if(use_eq > 0)
                cout << a[i], use_eq--;
            else
                cout << get(a[i], b[i]);
        } else {

            if(a_curr < use_diff)
                cout << a[i], a_curr++;
            else if(b_curr < use_diff)
                cout << b[i], b_curr++;
            else
                cout << get(a[i], b[i]);
        }
    }

    cout <<"\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
