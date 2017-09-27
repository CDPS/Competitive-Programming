#include <bits/stdc++.h>

using namespace std;

int p[100];

int hartals(int n,int d){
    set<int> st;
    for(int i=0;i<d;i++){
        for(int j=p[i];j<=n;j+=p[i])
            if(!(j%7==0 || j%7==6))
                    st.insert(j);
    }
    return st.size();
}

int main(){
    int t,d,n;
    scanf("%d",&t);

    while(t--){
        scanf("%d",&n); scanf("%d",&d);
        for(int i=0;i<d;i++)
            scanf("%d",p+i);
        int res = hartals(n,d);
        printf("%d\n",res);
    }
    return 0;
}

