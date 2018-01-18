#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> node;

int main(){

    int n,w,d,c;

    scanf("%d %d",&n,&w);

    vector<node> v;

    for(int i=0;i<n;i++){
        scanf("%d %d",&d,&c);
        v.push_back(node(d,c));
    }
    sort(v.begin(),v.end());

    int mini = v[0].first;
    int maxi = v[v.size()-1].first;

    int ans =0,k=0;
    for(int i=mini;i<=maxi+1;i++){

        int acc =0;

        while( k<v.size() && (v[k].first==i || v[k].first+1==i)){

            if(v[k].second+acc>w){
                v[k].second = (v[k].second+acc) - w;
                acc+= w;
                cout << v[k].first << " " << v[k].second << " " << ans << "\n";
                cin.get();
                break;
            }else{
                acc  = acc + v[k].second;
                cout << v[k].first << " " << v[k].second << " " << ans << "\n";
                cin.get();
            }
            k++;
        }
        ans= ans + acc;
    }
    printf("%d",ans);
    return 0;
}
