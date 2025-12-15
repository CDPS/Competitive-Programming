#include <bits/stdc++.h>

using namespace std;

int t, n;
int pfx[41];

bool check(int a, int b, int c){
    return (a==b && a==c) || (a!=b && a!=c && b!= c);
}

void solve(){

    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> pfx[i], pfx[i]+=pfx[i-1];

    for(int i=1;i<=n-2;i++){
        for(int j=i+2;j<=n;j++){
            int a = pfx[i];
            int b = pfx[j-1]-pfx[i];
            int c = pfx[n]-pfx[j-1];

            if(check(a%3, b%3, c%3)){
                cout << i << " " << j-1 << "\n";
                return;
            }
        }
    }

    cout << 0 << " " << 0 << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();


    return 0;
}
