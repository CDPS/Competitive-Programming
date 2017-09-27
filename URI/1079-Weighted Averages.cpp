#include <bits/stdc++.h>

using namespace std;


int main(){

    int t;
    scanf("%d",&t);


    while(t--){
        double a,b,c;
        cin >> a >> b >>c;
        printf("%.1lf\n",( (a*2.0) + (b*3.0) + (c*5.0) )/10.0);
    }
    return 0;
}
