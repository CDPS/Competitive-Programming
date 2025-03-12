#include <bits/stdc++.h>

using namespace std;

int a[200000];
int f[200001];
int m = 1e9 + 7;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, mini;
    cin >> t;

    f[0] = 1;
    for(int i=1;i<=200000;i++)
        f[i] = (1ll* i * f[i-1])%m;

    while(t--){

        cin >> n;
        mini = m;
        for(int i=0;i<n;i++)
            cin >> a[i], mini = min(a[i], mini);

        int accMini = 0, superMasks = 0;
        for(int i=0;i<n;i++){
            if(a[i]==mini) accMini++;
            if((a[i]&mini) == mini) superMasks++;
        }

        int ans = 0;
        if(superMasks == n){
            ans = (1ll*accMini*(accMini-1) )%m;
            ans = (1ll*ans*f[n-2])%m;
        }

        cout << ans  << "\n";
    }
    return 0;
}
