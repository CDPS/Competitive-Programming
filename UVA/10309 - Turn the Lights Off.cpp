#include <bits/stdc++.h>

using namespace std;

vector< vector<bool>  > g, l;

int top = (1<<10);

void flip(int x, int y){
    if(x-1>=0)g[x-1][y]=!g[x-1][y];
    if(x+1<10)g[x+1][y]=!g[x+1][y];
    if(y-1>=0)g[x][y-1]=!g[x][y-1];
    if(y+1<10)g[x][y+1]=!g[x][y+1];
    g[x][y]=!g[x][y];
}

int acc,ans;

void turnFirstRow(int mask){

    for(int i=0;i<10;i++)
        if(( mask & ( 1 << i ) )) flip(0,i), acc++;
}

bool isValid(){
    for(int j=0;j<10;j++)
        if(g[9][j])
            return false;
    return true;
}

void chaseLights(){

    for(int i=1;i<10;i++)
        for(int j=0;j<10;j++)
            if(g[i-1][j]) flip(i,j) , acc++;

    if(!isValid())
        acc=1000;
}

// thanks to Leonardo Boshell for supporting cp students
//reference http://lbv-pc.blogspot.com.co/2012/08/turn-lights-off.html

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string name; char c;

    g = l= vector< vector<bool> > (10, vector<bool> (10,0));

    while(cin >> name){
        if(name=="end")
            break;

        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++){
                cin >> c; l[i][j] = (c=='#')? 0:1;
            }

        ans =1000;

        for(int i=0;i<=top;i++){
            g=l;
            acc=0;
            turnFirstRow(i);
            chaseLights();
            ans= min(ans,acc);
        }
        cout << name << " " << ans<< "\n";
    }
    return 0;
}
