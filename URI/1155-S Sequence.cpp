#include <bits/stdc++.h>
using namespace std;

int main(){

    double res=0;
    for(int i=1;i<=100;i++)
        res+=(double)1/(double)i;
    printf("%.2lf\n",res);
    return 0;
}
