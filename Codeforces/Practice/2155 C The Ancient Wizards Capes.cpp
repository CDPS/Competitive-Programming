#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[100000];

bool check(const vector<int>& c) {
    int acc = 1;
    for(int j = 1; j < n; j++)
        acc += c[j];
    return acc == a[0];
}

int solve(){

    cin >> n;
    for(int i=0; i < n ; i++) cin >> a[i];

    int prev = -1;
    bool all_zeroes = true;


    vector<int> c(n, -1);
    for(int i = 1; i < n; i++){
        int diff = a[i] - a[i-1];

        if( abs(diff) > 1) return 0;
        else if(diff == 1 && all_zeroes){
            all_zeroes = false;
            c[i-1] = c[i] = 0;
            for(int j = i - 2; j >= 0; j--)
                c[j] = !c[j+1];
        }
        else if(diff == -1 && all_zeroes){
            all_zeroes = false;
            c[i-1] = c[i] = 1;
            for(int j = i - 2; j >= 0; j--)
                c[j] = !c[j+1];
        }
        else if(diff == 1 && !all_zeroes){
            if(c[i-1] != 0) return 0;
            c[i] = 0;
        }
        else if(diff == -1 && !all_zeroes){
            if(c[i-1] != 1) return 0;
            c[i] = 1;
        }
        else if(diff == 0 && !all_zeroes){
            c[i] = !c[i-1];
        }
    }

    if(!all_zeroes) return check(c);

    int ans = 0;
    vector<int> c1(n), c2(n);

    c1[0] = 0;
    for(int i = 1; i < n; i++) c1[i] = !c1[i-1];
    c2[0] = 1;
    for(int i = 1; i < n; i++) c2[i] = !c2[i-1];

    return check(c1) + check(c2);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
