#include <bits/stdc++.h>

using namespace std;

int a[100000];
int b[100000];
int c[100000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n,x;

    unordered_map<int,int> mp;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i], mp[a[i]] = i;
    for(int i=0;i<n;i++) cin >> b[i];

    int ans = 0;

    int low = 0;
    for(int i=0;i<n;i++){
        if(b[i]!= a[low]) ans++, c[ mp[b[i]] ] = 1;
        if(b[i]== a[low]){
            c[ mp[b[i]] ] =1;
            while(low < n && c[low]) low++;
        }
    }

    cout << ans << "\n";

    return 0;
}
