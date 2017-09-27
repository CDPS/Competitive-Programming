#include <bits/stdc++.h>

using namespace std;

int main(){

    long y,n;

    while(scanf("%ld",&y)==1){

        scanf("%ld",&n);

        vector<long> a(n);
        for(int i=0;i<n;i++)
            scanf("%ld",&a[i]);

        long maxi=-1,l,h;

        for(long i=0;i<n;i++){

           long index =  long(upper_bound( a.begin(), a.end(), a[i]+y-1) - a.begin())-1;

           if(index-i+1>maxi)
                maxi = index-i+1,l=i,h=index;
        }

        printf("%ld %ld %ld\n",maxi,a[l],a[h]);
    }
    return 0;
}
