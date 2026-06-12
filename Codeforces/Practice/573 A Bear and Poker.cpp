#include <bits/stdc++.h>

using namespace std;

int t = 1, n;
int a[100000];

bool solve(){

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> a[i];
        while(a[i]%2==0) a[i]/=2;
        while(a[i]%3==0) a[i]/=3;
    }

    for(int i =1;i <n; i++)
        if(a[i] != a[i-1])
            return false;

    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << ( solve()? "YES" : "NO") << "\n";

    return 0;
}
