#include <bits/stdc++.h>

using namespace std;

const string endline = "\n";

int main() {

    ios_base::sync_with_stdio(false);cin.tie(NULL);
    long t, n, ans;
    cin >> t;
    while(t--) {
        cin >> n;
        ans = 0;
        for(long i = 1; i<n; i++)
            if(n%i==0) {
                ans+=i;
            }

        if(ans == n)
            cout << "perfect" << endline;
        else if(ans < n)
            cout << "deficient" << endline;
        else if(ans > n)
            cout << "abundant" << endline;
    }

    return 0;
}
