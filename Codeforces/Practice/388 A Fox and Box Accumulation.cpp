#include <bits/stdc++.h>

using namespace std;

int t = 1, n;

int a[100];
int v[100];

int solve(){

    cin >> n;
    for(int i=0; i < n ;i++)
        cin >> a[i];

    sort( a , a + n);

    for(int i=0;i<n;i++){
        for(int j=0;j<100;j++)
            if(v[j] <= a[i]){
                v[j]++; break;
            }
    }

    int ans = 0;
    for(int i=0;i < 100; i++)
        ans+= (v[i]!=0);

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n" ;

    return 0;
}

