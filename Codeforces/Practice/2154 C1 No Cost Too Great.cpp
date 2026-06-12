#include <bits/stdc++.h>

using namespace std;

const int MAX = 200000;

int t, n;
int      a[MAX];
int      b[MAX];
int is_fac[MAX+1];

void clean(vector<int> &factors){
    for(int x : factors)
        is_fac[x] = false;
}

int solve(){

    cin >> n;

    int even_count = 0;
    for(int i =0; i < n; i++ )
        cin >> a[i], even_count+= a[i]%2==0;
    for(int i =0; i < n; i++ )
        cin >> b[i];

    if(even_count >= 2) return 0;
    vector<int> factors;

    bool check = false;
    for(int i = 0; i < n; i++) {
        int x = a[i];
        for(int p = 2; p*p <= x; p++) {
            if(x % p == 0) {
                if( is_fac[p] ) {
                    check = true;
                } else {
                    is_fac[p] = true;
                    factors.push_back(p);
                }
                while(x % p == 0) x /= p;
            }
        }

        if(x > 1) {
            if( is_fac[x] ) {
                check = true;
            } else {
                is_fac[x] = true;
                factors.push_back(x);
            }
        }
        if(check ) break;
    }

    if(check ){
        clean(factors);
        return 0;
    }

    int ans = 2;
    for(int i = 0; i < n; i++) {
        int y = a[i] + 1;
        for(int p = 2; p*p <= y; p++) {
            if(y % p == 0) {
                if(is_fac[p]){ ans =  1; break; }
                while(y % p == 0) y /= p;
            }
        }
        if(y > 1 && is_fac[y] ){ ans =  1; break; }
    }

    clean(factors);

    return ans;
}


int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
