#include <bits/stdc++.h>

using namespace std;

map< string ,string > parent; //valor representativo del set
map<string, int>  Rank; //maxima altura del set
map<string , int> cant; //Cantidad de nodos por set

int n;              //Cantidad de sets

//Path Compression
string findset(string x){
    if(parent[x]!=x)
        parent[x] = findset(parent[x]);
    return parent[x];
}

//Union By rank
int unionset(string x, string y){
    string  px= findset(x); string py= findset(y);

    if(px==py) return cant[px];

    int r1 = Rank[px];
    int r2 = Rank[py];

    if(r1 < r2 ){ parent[px]=py;  cant[py]+=cant[px] ;return cant[py];}
    else if( r2< r1){ parent[py]=px; cant[px]+= cant[py];  return cant[px];}
    else { parent[py]=px; Rank[px]++; cant[px]+= cant[py]; return cant[px];}
}

int main(){

    int t;
    cin >> t;

    while(t--){
        cin >> n;

        vector < pair<string, string >  >v;
        string s1, s2;

        for(int i=0;i<n;i++){
            cin >> s1 >> s2;
            v.push_back(make_pair(s1, s2));
            parent[s1]=s1; parent[s2]=s2;
            cant[s1]= cant[s2] = Rank[s1] = Rank[s2] = 1;
        }

         for(int i=0;i<n;i++){
            printf("%d\n", unionset(v[i].first, v[i].second));
        }

        parent.clear();
        Rank.clear();
        cant.clear();
    }
    return 0;
}

