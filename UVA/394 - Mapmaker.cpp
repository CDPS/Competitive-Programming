#include <bits/stdc++.h>

using namespace std;

struct node{
    int base;
    int byteSize;
    int dimension;
    vector<int> h,l;
    node(int a, int b, int c, vector<int> d, vector<int> e){
        base = a;
        byteSize = b;
        dimension = c;
        l=d;
        h = e;
    }
    node(){}
};

map<string,node> mp;

int calc(vector<int> references, node index ){
    vector<int> cs(index.dimension);
    cs[index.dimension-1] = index.byteSize;
    for(int i= index.dimension-2; i >=0 ;i--)
        cs[i] = cs[i+1] * ( index.h[i+1] - index.l[i+1] + 1 );

    int res = index.base;
    for(int i=0;i<cs.size();i++)
        res-= cs[i] * index.l[i];
    for(int i=0;i<cs.size();i++)
        res += references[i]*cs[i];
    return res;
}

int main(){

    int n,q;

    cin >> n >> q;

    string name;
    int base,byteSize,dimension;

    while(n--){
        cin >> name >> base >> byteSize >> dimension;
        vector<int> h(dimension),l(dimension);
        for(int i=0;i<dimension;i++)
            cin >> l[i] >> h[i];
        node index = node(base,byteSize,dimension,l,h);
        mp[name] = index;
    }

    while(q--){
        cin >> name;
        node index = mp[name];
        vector<int> references (index.dimension);
        for(int i=0;i< index.dimension;i++)
            cin >> references[i];
        int res = calc(references, index);
        cout<< name << "[" << references[0];
        for(int i=1;i< index.dimension;i++)
            cout  << ", " << references[i];
        cout << "] = " << res <<"\n";
    }

    return 0;
}
