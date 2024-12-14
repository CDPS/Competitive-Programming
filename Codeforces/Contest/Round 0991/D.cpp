#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t; string s;
    cin >> t;

    while(t--){
        cin >> s;
        int n = s.size();
        for(int i =0;i<n;i++){

            int current = s[i] - '0';
            int maxi = current, maxid = i;

            for(int j = 1; j <=9 && i+j < n; j++){
                if((s[i+j] -'0')-j > maxi )
                    maxi = (s[i+j] -'0')-j, maxid = j + i;
            }

            s[maxid] = maxi + '0';
            for(int k = maxid; k > i; k--) swap(s[k], s[k-1]);
        }

        cout << s << "\n";
    }
    return 0;
}
