#include <bits/stdc++.h>

using namespace std;

int t =1, n, k, c;
int a[200000];

int solve(){

    cin >> n >> k >> c;
    for(int i=0;i<n;i++) cin >> a[i];

    int ans  = 0, curr = 0;
    for(int i=0;i < n; i++){
        if(a[i] > k){
            ans+= max(0 , curr-c + 1);
            curr = 0;
            continue;
        }
        curr++;
    }


    return ans + max(0 , curr-c+ 1);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    while(t--)
        cout << solve() << "\n" ;

    return 0;
}


