#include <bits/stdc++.h>

using namespace std;

int parent[20002];
int Rank  [20002];

int n;

int findset(int x){
    if(parent[x]!=x)
        parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x, int y){
    int px= findset(x); int py= findset(y);
    if(px==py) return;
    if(Rank[px]< Rank[py]) parent[px]=py;
    if(Rank[py]< Rank[px]) parent[py]=px;
    if(Rank[py]==Rank[px]){ parent[py]=px; Rank[px]++;}
}

int getEnemie(int x){
    return n+x;
}

bool areFriends(int x,int y){
    if(findset(x)==findset(y) || findset(getEnemie(x))==findset(getEnemie(y)))
        return true;
    return false;
}

bool areEnemies(int x,int y){
    if(findset(x)==findset(getEnemie(y))  || findset(getEnemie(x)) == findset(y))
        return true;
    return false;
}

void setFriend(int x, int y){
    if(!areEnemies(x,y)){
        unionset(x,y);
        unionset(getEnemie(x),getEnemie(y));
    }else{
        printf("-1\n");
    }
}

void setEnemies(int x, int y){
    if(!areFriends(x,y)){
        unionset(x,getEnemie(y));
        unionset(getEnemie(x),y);
    }else{
        printf("-1\n");
    }
}

int main(){

    scanf("%d",&n);

    for(int i=0;i<2*n;i++){
        parent[i]=i; Rank[i]=1;
    }

    int c, x, y;

    while(scanf("%d %d %d",&c,&x,&y)){

        if(c==0 && x==0 && y==0 ) break;

        if(c==1) setFriend(x,y);

        if(c==2) setEnemies(x,y);

        if(c == 3)printf("%d\n", areFriends(x,y) ? 1 : 0);

        if(c == 4)printf("%d\n", areEnemies(x,y) ? 1 : 0);
    }

    return 0;
}
