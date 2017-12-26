#include <bits/stdc++.h>

using namespace std;

long cycle(long n){
    long r =0;
    do{
        n = (n%2==0)? n/2: 3*n +1;
        r++;
    }while(n!=1);
    return r;
}

int main(){

    long l,h;
    while( scanf("%ld %ld", &l, &h) ){

        if(l==0 && h ==0) break;

        if(l>h) swap(l,h);

        int maxi=-1;
        int idx = -1;
        for(long i= l ;i<=h;i++){
            long r = cycle(i);
            if(r > maxi)
                maxi = r, idx = i;
        }
        printf("Between %ld and %ld, %ld generates the longest sequence of %ld values.\n",l,h,idx,maxi);
    }
    return 0;
}
