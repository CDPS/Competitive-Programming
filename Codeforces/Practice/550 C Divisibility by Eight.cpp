#include <bits/stdc++.h>

using namespace std;

string s;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> s;

    for(int i=0;i<s.size();i++){
        if( (s[i]-'0')%8 == 0 ){
            cout << "YES" << "\n";
            cout << s[i] << "\n";
            return 0;
        }
        for(int j=i+1;j<s.size();j++){
            if( ( (10*(s[i]-'0')) + (s[j]-'0') )%8 == 0 ){
                cout << "YES" << "\n";
                cout << (10*(s[i]-'0')) + (s[j]-'0') << "\n";
                return 0;
            }
            for(int k=j+1;k<s.size();k++){
                int n = (100*(s[i]-'0')) + (10*(s[j]-'0')) + (s[k]-'0');
                if(n%8==0){
                    cout << "YES" << "\n";
                    cout << n << "\n";
                    return 0;
                }
            }
        }
    }

    cout << "NO" << "\n";


    return 0;
}
