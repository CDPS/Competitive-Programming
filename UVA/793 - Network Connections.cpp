#include <bits/stdc++.h>

using namespace std;


int parent[100000]; //valor representativo del set
int Rank  [100000]; //maxima altura del set
int cant  [100000]; //Cantidad de nodos por set
int n;              //Cantidad de sets

//Path Compression
int findset(int x){
    if(parent[x]!=x)
        parent[x] = findset(parent[x]);
    return parent[x];
}

//Union By rank
void unionset(int x, int y){
    int px= findset(x); int py= findset(y);
    if(px==py) return;
    if(Rank[px]< Rank[py]){ parent[px]=py;  cant[py]+= cant[px];}
    if(Rank[py]< Rank[px]){ parent[py]=px; cant[px]+= cant[py]; }
    if(Rank[py]==Rank[px]){ parent[py]=px; Rank[px]++; cant[px]+= cant[py]; }
}

bool isSameSet(int x,int y){
    return findset(x)==findset(y);
}

int main(){

    int t,n,c1,c2;
    char c;

    cin >> t;

    bool first=true;
    while(t--){

        cin >> n;  cin.ignore();
        for(int i=0;i<n;i++){
            parent[i]=i; Rank[i]= cant[i]=1;
        }

        if(!first)cout << "\n";
        first=false;

        string s;
        int r1=0,r2=0;

        while(getline(cin,s) && s!=""){
            stringstream ss(s);
            ss >> c >> c1 >> c2;
            c1--; c2--;
            if(c=='c'){
                unionset(c1,c2);
            }else{
                if(isSameSet(c1,c2))r1++;
                else r2++;
            }
        }

        cout << r1 << "," << r2 << "\n";
    }

    return 0;
}
