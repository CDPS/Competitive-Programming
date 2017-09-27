#include <bits/stdc++.h>

using namespace std;

int parent[26]; //valor representativo del set
int Rank  [26]; //maxima altura del set
int cant  [26]; //Cantidad de nodos por set
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
    n--;
}

int main(){


    int t;
    cin >> t;

    char maxSet;
    bool f =1;
    while(t--){

        cin >> maxSet; cin.ignore();

        if(!f)cout << "\n"; f=0;

        n = maxSet - 64;

        for(int i=0;i<n;i++){
            parent[i]=i; Rank[i] = cant[i]=1;
        }

        string s;
        while(getline(cin, s) && s!=""){
            unionset(s[0]-'A',s[1]-'A');
        }
        cout << n << "\n";
    }

    return 0;
}
