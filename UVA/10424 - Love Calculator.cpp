#include <bits/stdc++.h>

using namespace std;

int getNumber(int n){

    int r  = n;
    while(r>=10){
        n=r;
        r=0;
        while(n){
            int d= n%10;
            n/=10;
            r+= d;
        }
    }
    return r;
}
int main(){
    string a,b;

    while(getline(cin,a)){
        getline(cin,b);
        int v1=0,v2=0;
        for(int i=0;i<a.size();i++){
            if ( (a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z') )
                v1 += (tolower(a[i])-'a')+1;
        }

        for(int i=0;i<b.size();i++){
            if ( (b[i]>='a' && b[i]<='z') || (b[i]>='A' && b[i]<='Z') )
                v2 += (tolower(b[i])-'a')+1;
        }
        v1 = getNumber(v1); v2 = getNumber(v2);
        if(v2>v1)
            swap(v2,v1);
        cout << fixed << setprecision(2) << (double(v2)/double(v1))*100.0 << " %\n";
    }
    return 0;
}
