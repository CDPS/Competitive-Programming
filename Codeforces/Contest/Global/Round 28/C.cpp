#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t; string s;
    cin >> t;

    while(t--){

        cin >> s;
        int n = s.size();
        int f=0;
        while(f<n){
            if(s[f]=='0')
                break;
            f++;
        }

        int ansx = 1, ansy = 1;
        if(f!=n){
            int  k = n - f ;
            string maxi = "";
            for(int i=0;i< f;i++){
                string temp = "";
                for(int j=0;j<k;j++)
                    temp= s[i+j]==s[f+j] ? temp+'0': temp+'1';
                if(temp > maxi)
                    maxi = temp, ansx = i+1, ansy = i+k;
            }
        }

        cout << 1 << " " << s.size() << " " << ansx << " " << ansy << "\n";
    }
    return 0;
}

