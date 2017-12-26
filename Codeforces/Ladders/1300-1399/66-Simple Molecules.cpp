#include <bits/stdc++.h>

using namespace std;

int a[3];

int main(){
    cin >> a[0] >> a[1] >> a[2];

    int ra,rb,rc;
    bool f=false;
    for(int i=0;i<=a[0];i++){
        ra = i;
        rb = a[0]-ra;

        if(ra <0 || rb <0 ) break;

        if(a[2] - rb == a[1]-ra  && a[2] - rb>=0){
            rc = a[2] - rb;
            f=true;
            break;
        }
    }

    if(f)
        cout << ra << " " << rc << " " << rb << "\n";
    else
        cout << "Impossible\n";

    return 0;
}
