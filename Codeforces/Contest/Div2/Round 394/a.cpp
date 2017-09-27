#include <bits/stdc++.h>

using namespace std;

int main(){


    int a,b;
    scanf("%d %d",&a,&b);

    bool f=0;

    if(a==0 && b==1)f=1;
    else if(a==0 && b==0)f=0;
    else if(a==b)f=1;
    else if(a==b-1)f=1;
    else if(b==a-1)f=1;

    if(f)printf("YES\n");
    else printf("NO\n");

    return 0;
}
