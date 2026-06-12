#include <bits/stdc++.h>

using namespace std;

int t = 1, n;
int a[1000];

bool check(){
    for(int i=0;i<n;i++)
        if(a[i] != i)
            return false;
    return true;
}

bool solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    if(check()) return true;

    for(int i=0;i<n;i++){
        for(int j =0; j < n; j++)
            a[j] = (j%2==0) ? (a[j] + 1)%n : ( a[j] - 1 +  n )%n;
        if(check())
            return true;
    }
    return false;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << (solve()? "Yes" : "No") << "\n";

    return 0;
}
