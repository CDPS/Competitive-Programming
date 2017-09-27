#include <bits/stdc++.h>

using namespace std;


int main(){
    int n,t;
    string s;

    cin >> n >> t;

    cin >> s;

    if(t>n)t=n;


    for(int i=0;i<t;i++){
        for(int j=0;j<s.size()-1;j++){
            if(s[j]=='B' && s[j+1]=='G'){
                swap(s[j],s[j+1]);
                j++;
            }
        }
    }

    cout << s << "\n";
    return 0;
}
