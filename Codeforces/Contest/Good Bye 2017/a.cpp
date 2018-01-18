#include <bits/stdc++.h>

using namespace std;

int main(){

    string a;
    int res=0;

    cin >> a;
    for(int i=0;i<a.size();i++){
        if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u'){
            res++;
        }
        if(a[i]>='0' && a[i]<='9'){
            int d = a[i]-'0';
            if(d%2)
                res++;
        }
    }
    cout << res << "\n";
    return 0;
}
