#include <bits/stdc++.h>

using namespace std;

int t = 1, n;
int a[100000];

int solve(){

    cin >> n;
    for(int i=0; i < n ;i++)
        cin >> a[i];

    int ans = a[0];
    int curr = 0;
    for(int i=1; i< n; i++){
        if(a[i] < a[i-1]) curr += a[i-1] - a[i];
        if(a[i] > a[i-1]){
            int needed = a[i] - a[i-1];
            int take = min( needed, curr );
            curr-= take;
            ans+= needed-take;
        }
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n" ;

    return 0;
}

