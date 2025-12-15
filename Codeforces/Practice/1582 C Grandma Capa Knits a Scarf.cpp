#include <bits/stdc++.h>

using namespace std;

int t, n;
string a;

int solve(){

    cin >> n >> a;

    int ans = n + 1;
    for(char c= 'a'; c<='z';c++){

        int i = 0, j = n -1, counts = 0;
        while(i < j ){
            if(a[i]== c && a[i] != a[j] )
                i++, counts++;
            else if(a[j]== c && a[i] != a[j] )
                j--, counts++;
            else if(a[j]== a[i])
                i++, j--;
            else
                counts= n + 1, j = 0, i = n;
        }
        ans = min(counts, ans);
    }

    return ans == n + 1? -1 : ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
