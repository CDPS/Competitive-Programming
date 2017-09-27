#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;

    scanf("%d",&t);

    long a[3];
    while(t--){

        int x,y;
        scanf("%d %d",&x,&y);

        a[0] = pow((3*x),2)+pow(y,2);
        a[1] = 2*pow(x,2)+pow((5*y),2);
        a[2] = -100*x+(pow(y,3));

        map<long, string> mp;

        mp[ a[0] ]= "Rafael";
        mp[ a[1] ]= "Beto";
        mp[ a[2] ]= "Carlos";

        sort( a , a+3 );

        cout << mp[ a[2] ]<<" ganhou"<< endl;
     }
    return 0;
}
