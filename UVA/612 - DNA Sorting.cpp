#include <bits/stdc++.h>

using namespace std;

struct node{
    string s;
    int inv, idx;

    node(string a, int b){ s=a; idx =b; inv=calc(a);}

    bool operator < (const node &a) const{
        if(inv == a.inv)
            return idx < a.idx;
        return inv < a.inv;
    }

    int calc(string a){
        int res=0;
        for(int i=0;i<a.length()-1;i++)
            for(int j=i+1;j<a.length();j++)
                if(a[i]>a[j])
                    res++;
        return res;
    }
};


int calc(string a){
    int res=0;

    int r [27];
    for(int i=0;i<a.length()-1;i++){
        memset(r,0,sizeof r);
        for(int j=i+1;j<a.length();j++){
            if(a[i]>a[j] && r[ a[j]- 'A' ] == 0){ res++;  r[a[j]- 'A' ]=1;}
        }
    }
    return res;
}

int main(){

    int t,l,n;
    string s;

    cin >> t;

    bool first=true;

    while(t--){

        vector<node > v;
        cin >> l  >> n;

        if(!first)
            cout << "\n";
        first= false;
        for(int i=0;i<n;i++){
            cin >> s;
            v.push_back(node(s,i));
        }

        sort(v.begin(),v.end());

        for(int i=0;i< n ;i++)
            cout << v[i].s << "\n";
    }

    return 0;
}
