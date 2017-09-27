#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> h,w;

long dp(){

    vector<long> acc = vector<long> (h.size(),0);

    long maxi = w[0];
    acc[0]=w[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if( h[j] < h[i] && acc[i] < acc[j] + w[i])
                    acc[i] = acc[j] + w[i];
        }
        if(acc[i]==0) acc[i] = w[i];
        maxi = max(maxi,acc[i]);
    }
    return maxi;
}

int main(){

    int t,caseno=1;
    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);
        h = w = vector<int> (n);

        for(int i=0;i<n;i++) scanf("%d",h.begin()+i);

        for(int i=0;i<n;i++) scanf("%d",w.begin()+i);

        long incresing = dp();

        reverse(h.begin(),h.end());
        reverse(w.begin(),w.end());

        long decresing = dp();

        if(incresing >= decresing)
            printf("Case %d. Increasing (%ld). Decreasing (%ld).\n",caseno++,incresing,decresing);
        else
            printf("Case %d. Decreasing (%ld). Increasing (%ld).\n",caseno++,decresing,incresing);

    }
    return 0;
}
