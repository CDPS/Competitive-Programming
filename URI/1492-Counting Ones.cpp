#include <bits/stdc++.h>

using namespace std;


int a[42];


long bits(long i)
{
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}


int main(){

    int t;
    scanf("%d",&t);

    while(t--){

        int n,k;

        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }


        long long m= 1 << n;

        priority_queue<long > pq;

        for(int i=1;i<m;i++){

            if(bits(i)==k){
                long b=1;
                for(int j=0;j<n;j++){
                    if( (i&(1<<j))!=0){
                        b&=a[j];
                    }
                }
                pq.push(b);
            }
        }


    }
    return 0;
}
