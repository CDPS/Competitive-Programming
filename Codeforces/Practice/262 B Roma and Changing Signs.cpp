#include <bits/stdc++.h>

using namespace std;

int n, k;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> k;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];


    int used=0;
    for(int i=0;i<n && used < k;i++){
        if(a[i] < 0 )
            a[i]*=-1, used++;
    }

    int mini= 1e9, ans = 0;
    for(int i=0;i<n;i++)
        mini = min(mini, a[i]), ans+=a[i];

    k-= used;


    cout << ans + (k%2*-2*mini ) << "\n";

    return 0;
}
