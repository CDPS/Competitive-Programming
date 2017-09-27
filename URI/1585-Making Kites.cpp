#include <bits/stdc++.h>

using namespace std;


int main(){


    int t;
    scanf("%d",&t);

    while(t--){


        int x,y;
        scanf("%d %d",&x,&y);

        int area= x*y;

        area/=2;

        printf("%d cm2\n",area);

    }
    return 0;
}
