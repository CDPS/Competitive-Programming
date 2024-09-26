#include <bits/stdc++.h>

using namespace std;

void f(string s){
    double ans = 0;
    double j = 1;
    for(int i=s.size()-1;i>=0;i--, j*= 26.0 ){
        double c= (s[i]-'a') + 1;
        ans += j*c;
    }
    cout << ans << '\n';
}

int main(){

    cout.setf(ios_base::fixed);
    cout.precision(0);

    string s;
    while(cin >> s && s[0]!='*'){
        f(s);
    }
    return 0;
}
