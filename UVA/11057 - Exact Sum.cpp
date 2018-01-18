#include <bits/stdc++.h>

using namespace std;

int a[10000],n,k;

int main(){

    while(scanf("%d",&n)==1){

        set<int> st;
        for(int i=0;i<n;i++)
            scanf("%d",a+i),st.insert(a[i]);
        scanf("%d",&k);

        int mini =10000000,ans1,ans2;
        for(int i=0;i<n;i++){
            if(a[i]<k && st.find(k-a[i])!=st.end()){
                int p1 = min(k-a[i],a[i]),p2 = max(k-a[i],a[i]);
                if(p2-p1<mini)
                    ans1 = p1,ans2=p2,mini=p2-p1;
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",ans1,ans2);
    }
    return 0;
}
