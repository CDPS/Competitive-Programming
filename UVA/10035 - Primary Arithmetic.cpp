#include <bits/stdc++.h>

using namespace std;

int main(){

    string a,b;
    while( (cin >> a >> b) ){

        if(a=="0" && b=="0")
            break;

        int res=0;
        int s1=a.size(),s2= b.size();

        for(int i=0;i<10-s1;i++)
            a = '0' + a;

        for(int i=0;i<10-s2;i++)
            b= '0' + b;

        bool f =0;
        for(int i=10;i>=0;i--){
            int r = int(a[i]-'0') + int(b[i]-'0');
            if(f) r++;
            if(r>=10) res++,f=1;
            else f=0;
        }

        if(res==0)
            cout << "No carry operation.\n";
        else if(res==1)
            cout << "1 carry operation.\n";
        else
            cout << res << " carry operations.\n";
    }
    return 0;
}
