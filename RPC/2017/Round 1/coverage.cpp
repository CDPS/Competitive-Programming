#include <bits/stdc++.h>

using namespace std;

int parent[5000];
int Rank  [5000];
int cant  [5000];

vector<int> g[5000];

int n;
int maxi;

int findset(int x){
    if(parent[x]!=x)
        parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x, int y){
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


        scanf("%d",&n);
        maxi=1;

        vector<circle> v;

        double x,y;

        for(int i=0;i<n;i++){
            scanf("%lf %lf",&x,&y);
            v.push_back(circle(x,y,1.0));
            parent[i]=i; cant[i]=Rank[i]=1;
        }

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(i!=j){
					double d = dis(v[i],v[j]);

                    if( d  <= v[i].r + v[j].r ){
                        unionset(i,j);
                        continue;
                    }

                    if(d<=4.0){
                        g[i].push_back(j);
                    }
                }
            }
        }

        int maxi=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<g[i].size();j++){
                int px =findset(i);
                int py =findset(j);
                if(px!=py){
                    maxi =  max(maxi,cant[px] + cant[py] +1 );
                }
            }
        }
        printf("%d\n",maxi);

    return 0;
}
