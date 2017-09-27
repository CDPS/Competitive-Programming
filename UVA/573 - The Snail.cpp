#include <bits/stdc++.h>

using namespace std;

int main(){
    double h,u,d,f;
    while(cin >> h >> u >> d >> f){
        if(h==0 && u == 0 && d==0 && f==0)
            break;
        int day=1;double r=0; double ff = double(f*u)/100.0;
        bool fl=0;
        while(true){
            r= r+u;
            if(r>h){ fl=1; break; }
            u = u-ff;
            if(u<0.0) u=0.0;
            r-=d;
            if(r<0.0)break;
            day++;
        }
        if(fl) cout << "success on day "<<day << "\n" ;
        else   cout << "failure on day "<<day << "\n";
    }
    return 0;
}
