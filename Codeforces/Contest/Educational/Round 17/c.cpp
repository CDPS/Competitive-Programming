#include <bits/stdc++.h>

using namespace std;


int acc[26];

struct node{

    char c;
    int pos;

    node(char a, int b){
        c=a;
        pos=b;
    }

    bool operator < (const node &a) const{
        if(c==a.c)
            pos < a.pos;
        return c < a.c;
    }

};

vector< node > v;

pair<int,int>  binarySearch(int n, char t){

   int lo = 0, hi = n-1;

   while (lo <= hi){
      int mid = (lo+hi)/2;

      if (v[mid].c == t)
         return make_pair( mid,v[mid].pos);
      else if (v[mid].c < t)
         lo = mid+1;
      else
         hi = mid-1;
    }

    return make_pair(-1,-1);
}

int main(){

    string a,b;

    cin >> a >> b;

    for(int i=0;i<b.size();i++){
        v.push_back(node(b[i],i));
    }

    sort(v.begin(),v.end());


    vector<node> res;
    res.push_back(node('l',-1));

    bool f = 0;

    for(int i=0;i<a.size();i++){

        pair<int,int>  index= binarySearch(v.size(),a[i]);

        if(index.first!=-1){
            cout << i << " " << index.second << "\n";
            if(index.second > res[ res.size()-1 ].pos){
                res.push_back(node(a[i],index.second) );
                v.erase(v.begin() + index.first );
                f=1;
            }
        }
    }

    if(f)
        for(int i=1;i<res.size();i++)
            cout << res[i].c;
    else cout << "-";
    cout << "\n";
    return 0;
}
