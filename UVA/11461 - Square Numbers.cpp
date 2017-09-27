#include <bits/stdc++.h>

using namespace std;

long acc[100001];

void Fill(){
    acc[0]=0;
    for(int i=1;i<100001;i++){
        int sr = sqrt(i);
        if(i==sr*sr)
            acc[i]=1 + acc[i-1];
        else
            acc[i]= acc[i-1];
    }
}

int main(){
    Fill();
    int l,h;
    while(scanf("%d %d",&l,&h)){
        if(l==0 && h==0)
            break;
        printf("%d\n",acc[h]-acc[l-1]);
    }
    return 0;
}
