#include <bits/stdc++.h>

using namespace std;

int t, n, k, x;

bool solve(){

    cin >> n >> k;
    
    vector<int> freq(n + 1, 0);
    for(int i=0; i <n; i++)
        cin >> x, freq[x]++;

    vector<int> pfx(n + 1, 0);
    for(int i= 1; i <=n; i++)
        pfx[i] = freq[i] + pfx[i-1];
    
    for(int i=n; i>=1; i--){
        if(freq[i]%2 ==0 && freq[i] >=2) 
            return true;
        if(freq[i]%2 && pfx[i-1] - pfx[max(0, i-k-1)] > 0)
            return true;
    }

    return false;
}

int main(){
    
    cin.sync_with_stdio(false); cin.tie(NULL);
    
    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO") << "\n";
    return 0;
}