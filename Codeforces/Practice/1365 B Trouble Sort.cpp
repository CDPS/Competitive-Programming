#include <bits/stdc++.h>

using namespace std;

int a[500];
int b[500];
int t, n;

bool check(){
    for(int i=1;i<n;i++)
        if(b[i]!=b[i-1]) return true;
    return false;
}

bool great(){
    for(int i=1;i<n;i++)
        if(a[i]<a[i-1]) return false;
    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--){

        cin >> n;

        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];

        if(check()){
            cout << "YES" << "\n";
            continue;
        }

        cout << (great()? "YES" : "NO" ) << "\n";
    }
    return 0;
}
