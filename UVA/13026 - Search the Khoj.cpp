#include <bits/stdc++.h>

using namespace std;

string a[1000];

int main(){

    int t, caseno = 1,n;
    string s;
    cin >> t;

    while(t--){

        cin >> n;
        for(int i=0;i<n;i++)
            cin >> a[i];

        cin >> s;

        cout << "Case " << caseno++ << ":" << "\n";
        for(int i=0;i<n;i++){
            int acc = 0;
            for(int j=0;j<s.size();j++){
                if(a[i][j]!=s[j])
                    acc++;
            }
            if(acc<=1)
                cout << a[i]<< "\n";
        }

    }
    return 0;
}
