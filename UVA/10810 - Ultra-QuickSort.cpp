#include <bits/stdc++.h>

using namespace std;

long a[500000];

const int oo= INT_MAX;

long long res;

int mergeR(int l, int mid, int h){

    int n1 = mid- l+1;
    int n2 = h - mid;

    long *left = new long[n1 + 1];
    long *right= new long[n2 + 1];

    int i = 0;
    for(; i < n1; i++)
        left[i] = a[ l  + i];

    int j = 0;
    for(; j < n2; j++)
        right[j] = a[mid + 1 + j];

    left [n1] = oo;
    right[n2] = oo;
    i = j = 0;

    for(int k = l; k <= h; k++ ){
        if(left[i] <= right[j]){
            a[k] = left[i++];
            res+= j;
        }
        else
            a[k] = right[j++];
    }
}

void mergeSort(int l, int h){

    if(l < h){
       int mid = (h + l) >> 1;
       mergeSort(l, mid);
       mergeSort(mid + 1, h);
       mergeR(l, mid, h);
    }
}

int main(){
    int n;
    while(scanf("%d",&n) && n){

        for(int i=0;i<n;i++)
            scanf("%ld",a+i);
        res=0;
        mergeSort(0,n-1);
        printf("%lld\n",res);
    }
    return 0;
}
