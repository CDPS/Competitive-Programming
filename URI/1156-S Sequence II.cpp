#include <bits/stdc++.h>

using namespace std;

int main(){

    double s =1.0;

    for(int i=3,j=2;i<=39;i+=2,j*=2){
        s+= (double)i/(double)j;
    }
    printf("%.2lf\n",s);
    return 0;
}
