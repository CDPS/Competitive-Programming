#include <bits/stdc++.h>

using namespace std;

struct node{
    long x,y,idx;
    node(long a,long b,long c){
        x=a; y=b; idx =c;
    }

    bool operator < (const node &a )const{
        if(x==a.x)
            return y > a.y;
        return x < a.x;
    }
};

int main(){

    int n;
    cin >> n;

    vector<node> v;

    long x,y;

    long mini =1000000001;
    long maxi = -1;

    for(int i=0;i<n;i++){
        cin >> x >> y;
        maxi = max(y,maxi);
        mini = min (x,mini);
        v.push_back(node(x,y,i));
    }

    sort(v.begin(),v.end());

    if(v[0].x== mini && v[0].y == maxi){
        cout << v[0].idx+1 << "\n";
    }else{
        cout << "-1\n";
    }
    return 0;
}
