#include <bits/stdc++.h>

using namespace std;

int b,s,c,pb,ps,pc,a[3];
long long r;
string ss;

bool canMake(long long x){
    long long rr =0;
    if( x*a[0]>1ll*b) rr +=( (x*a[0]) - 1ll*b) * pb;
    if( x*a[1]>1ll*s) rr +=( (x*a[1]) - 1ll*s) * ps;
    if( x*a[2]>1ll*c) rr +=( (x*a[2]) - 1ll*c) * pc;
    return rr<=r;
}

long long BinarySearch(){
    long long l=0, h = 1000000000100,m;
    while(l<h){
        m = l + ( (h-l+1)/2 );
        if(!canMake(m))
             h = m-1;
        else l = m;
    }
    return l;
}

int main(){

    cin >> ss;
    for(int i=0;i<ss.size();i++){
        if(ss[i]=='B') a[0]++;
        if(ss[i]=='S') a[1]++;
        if(ss[i]=='C') a[2]++;
    }

    cin >> b  >> s >> c;
    cin >> pb >>ps >> pc;
    cin >> r;
    cout << BinarySearch() << "\n";
    return 0;
}
