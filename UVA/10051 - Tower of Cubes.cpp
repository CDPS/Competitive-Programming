#include <bits/stdc++.h>

using namespace std;

string  names[6]={ "front", "back", "left", "right", "top", "bottom" };
int    c[500][6];
int    l[500][6];
pair<int,int> path[500][6];
int n,caseno=1;

int assingColor(int side){
    if( side ==0)
        return 1;
    if(side == 1)
        return 0;
    if( side ==2)
        return 3;
    if( side ==3)
        return 2;
    if( side ==4)
        return 5;
    return 4;
}

void printPath(int x,int k){

    if(path[x][k]!=make_pair(-1,-1)){
        printPath(path[x][k].first,path[x][k].second);
    }
    cout << x+1 << " " <<names[k] << "\n";
}

void dp(){

   for(int i=0;i<n;i++){
        for(int j=0;j<6;j++)
            l[i][j]=0, path[i][j]=make_pair(-1,-1);
   }

    for(int i=0;i<6;i++)
        path[0][i]=make_pair(-1,-1), l[0][i]=1;

    int maxi=1;int ii=0,kk=0;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            for(int k=0;k<6;k++){
                for(int h=0;h<6;h++){
                    if(c[i][k]== c[j][ assingColor(h) ] && l[i][k] < l[j][h] +1 ){
                        l[i][k]=l[j][h];
                        path[i][k]=make_pair(j,h);
                    }
                }
            }
        }
        for(int k=0;k<6;k++){
            l[i][k]++; if(l[i][k]>maxi) maxi = l[i][k], ii=i,kk=k;
        }
    }
    cout <<"Case #"<<caseno++ << "\n";
    cout << maxi << "\n";
    printPath(ii,kk);
}

int main(){
    cin.sync_with_stdio(false); cin.tie(NULL);
    bool first = true;
    while( cin >> n && n){
        if(!first) cout << "\n";
        first= false;
        for(int i=0;i<n;i++)
            cin >> c[i][0] >> c[i][1] >> c[i][2] >> c[i][3] >> c[i][4] >> c[i][5];
        dp();
    }
    return 0;
}
