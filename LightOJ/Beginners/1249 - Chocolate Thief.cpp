#include<bits/stdc++.h>

using namespace std;
long a[100];
string b[100];


void sorting(int n){

    for(int j=0;j<n-1;j++)
    {
      int  p=j;
        for(int k=j+1;k<n;k++)
        {
            if(a[k]<a[p]){
                p = k;
            }
        }
        if(p!=j){
            swap(a[j],a[p]);
            swap(b[j],b[p]);
        }
    }
}
int main(){

    int t, caseno=1;
    int n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int w,h,p;
        for(int i=0; i<n;i++){
            string as;
            cin>>as;

            scanf("%d",&w);
            scanf("%d",&h);
            scanf("%d",&p);

            a[i]=w*h*p;
            b[i]=as;
        }
        sorting(n);
        if(a[0]==a[n-1]){
            printf("Case %d: no thief\n",caseno++);
        }else{
            cout << "Case " << caseno++ << ": "<< b[n-1]<<" took chocolate from " <<b[0]<<endl;
        }

    }

    return 0;
}
