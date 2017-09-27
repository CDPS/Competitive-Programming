#include <bits/stdc++.h>

using namespace std;

int parent[100]; //valor representativo del set
int Rank  [100]; //maxima altura del set
int cant  [100]; //Cantidad de nodos por set

int n;              //Cantidad de sets
int maxi;

//Path Compression
int findset(int x){
    if(parent[x]!=x)
        parent[x] = findset(parent[x]);
    return parent[x];
}

//Union By rank
void unionset1(int x, int y){
    int px= findset(x); int py= findset(y);
    if(px==py) return;
    if(Rank[px]< Rank[py]){ parent[px]=py;  cant[py]+= cant[px]; maxi=max(  maxi, cant[py]); }
    if(Rank[py]< Rank[px]){ parent[py]=px; cant[px]+= cant[py]; maxi=max(  maxi, cant[px]);}
    if(Rank[py]==Rank[px]){ parent[py]=px; Rank[px]++; cant[px]+= cant[py]; maxi=max(  maxi, cant[px]);}
}

struct circle{
    double x,y,r;
    circle(double a, double b, double c){
        x=a; y=b; r=c;
    }
};

double dis(circle a, circle b){
    return sqrt( ((a.x-b.x)*(a.x-b.x))  +  ( (a.y-b.y)*(a.y-b.y) ) );
}

int main(){

    while( scanf("%d",&n) && n!=-1){

        maxi=0;
        if(n==0){ printf("The largest component contains %d rings.\n",maxi); continue;}

        maxi=1;

        vector<circle> v;
        double x,y,r;

        for(int i=0;i<n;i++){
            scanf("%lf %lf %lf",&x,&y,&r);
            v.push_back(circle(x,y,r));
            parent[i]=i; cant[i]=Rank[i]=1;
        }

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(i!=j){
					double d = dis(v[i],v[j]);

                    if(d + v[i].r < v[j].r ||  d + v[j].r < v[i].r  )
                            continue;
                    else if( d  <= v[i].r + v[j].r ){
                        unionset1(i,j);
                    }
                }
            }
        }
        printf("The largest component contains %d ring%s.\n",maxi,maxi==1? "":"s");
    }

    return 0;
}
