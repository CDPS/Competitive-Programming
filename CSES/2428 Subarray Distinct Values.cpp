#include <bits/stdc++.h>

using namespace std;

int a[200000];

int main(){

    int n, k;
    cin >> n >> k;

    for(int i=0;i<n;i++) cin >> a[i];

    map<long long, int> mp;
    set<int> last;

    long long ans = 0;

    for(int i=0, j = 0; i<n && j < n ;i++){

        while(j < n ){
            mp[ a[j++] ]++;
            if(mp.size() > k){
                mp[ a[j-1] ]--;
                j--;
                break;
            }
        }

        long long x = j-i;
        ans += ((x+1)*x)/2;
        if(last.count(i)) ans--;
        mp[ a[i] ]--;
        last.insert(j-1);
        if(mp[a[i]] == 0) mp.erase(a[i]);
    }
    cout << ans  << "\n";
    return 0;
}
