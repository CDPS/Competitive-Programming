#include <bits/stdc++.h>

using namespace std;

bool a[102];

int main(){

    int n, ini;
    cin >> n >> ini;

    a[0]= true;
    a[n+1]=true;

    for(int i=1;i<=n;i++)
        cin >> a[i];

    int low= ini, high =ini;
    int ans =0;

    while(low != 0 || high!=n+1){

        if(a[low] && a[high]){
            if(low==high|| low==0||high==n+1 )
                ans++;
            else
                ans+=2;
        }

        if(low > 0) low--;
        if(high<=n) high++;
    }

    cout << ans << "\n";
    return 0;
}
