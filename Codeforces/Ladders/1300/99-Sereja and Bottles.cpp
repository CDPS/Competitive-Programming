#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    scanf("%d",&n);
    map<int,vector<int> > mp;
    vector<int> v(n);
    vector<int> r(n,0);

    int a,b;
    for(int i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        a--,b--;
        mp [a].push_back(i);
        v[i]=b;
    }

    for(int i=0;i<n;i++){
        for(int j=0; j< mp[  v[i] ].size();j++){
            if(mp[ v[i] ][j] !=i)
                r [  mp[ v[i] ][j] ]=1;
        }
    }

    int ans=0;
    for(int i=0;i<n;i++)
        ans+=r[i];
    printf("%d\n",n-ans);
    return 0;
}
