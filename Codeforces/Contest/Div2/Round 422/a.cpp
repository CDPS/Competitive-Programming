#include <bits/stdc++.h>

using namespace std;

int main(){

    long a,b;
    cin >> a >> b;
    long r = min(a,b);
    long long ans =1;
    for(int i=1;i<=r;i++)
        ans*=i;
    cout << ans << "\n";
    return 0;
}
