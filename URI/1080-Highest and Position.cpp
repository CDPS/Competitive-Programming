#include <bits/stdc++.h>

using namespace std;

int main(){

    int maxi=-1;
    int j=0;
    int num;
    for(int i=0;i<100;i++){
        scanf("%d",&num);
        if(num>maxi){
            maxi=num;
            j=i;
        }
    }
    printf("%d\n",maxi);
    printf("%d\n",j+1);
    return 0;
}
