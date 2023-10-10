#include <bits/stdc++.h>

using namespace std;

int main(){

    string a;
    cin >> a;

    bool res = false;
    if(a.size()> 3 ){
        int i=0;
        int cc = 0;
        for(;i<a.size()-1;i++){
            if(a[i]=='A' && a[i+1] == 'B'){
                cc++;
                break;
            }
        }

        for(int j=i+2;j<a.size()-1 && cc == 1;j++){
            if(a[j]=='B' && a[j+1] == 'A'){
                cc++;
                break;
            }
        }

        if(cc < 2 ){
            cc = 0;
            i=0;

            for(;i<a.size()-1;i++){
                if(a[i]=='B' && a[i+1] == 'A'){
                    cc++;
                    break;
                }
            }

            for(int j=i+2;j<a.size()-1 && cc == 1;j++){
                if(a[j]=='A' && a[j+1] == 'B'){
                    cc++;
                    break;
                }
            }
        }

        res = cc == 2;
    }


    cout  << ( (res)? "YES" : "NO" ) << "\n";
    return 0;
}

