#include <bits/stdc++.h>

using namespace std;

int ra,rb,rc;
int a,b,c,d;

void Find(){
    bool f=false;
    for(int i=1;i<=200 && !f;i++)
        for(int j=1;j<=200 && !f;j++)
            for(int k=1;k<=200 && !f;k++)
                if( c <= i && c*2 >=i && d <= i && d*2 >=i   && b <= j && b*2 >=j &&  d*2 <j && a <= k && a*2 >=k &&  d*2 <k && i<j && j<k)
                    ra = k,rb=j,rc=i, f= true;
    if(f)
        cout << ra << " " << rb << " " << rc << "\n";
    else
        cout << -1 << "\n";
}

int main(){
    cin >> a >> b >> c >> d;
    Find();
    return 0;
}
