#include <bits/stdc++.h>

using namespace std;

long t, sx, sy, tx, ty;
bool e,w,s,n,fe,fw,fs,fn;

string ss;

void check(){
    n = s = e = w =0 ;
    if(ty > sy ) n = 1;
    if(sy > ty)  s = 1;
    if(tx > sx)  e = 1;
    if(sx > tx)  w = 1;
}

bool isValid(char c){
    if(c=='N' && n) return 1;
    if(c=='S' && s) return 1;
    if(c=='E' && e) return 1;
    if(c=='W' && w)  return 1;
    return 0;
}

long res =100000000;
bool r = 0;

void backtrack( int x, int y, int idx, long time){

    if(x==tx && y == ty){ r=1,res=min(res,time); return; }
    if(idx == t) return;

    if(isValid(ss[idx])){
        if(ss[idx]=='N' && y != ty) y++;
        if(ss[idx]=='S' && y != ty) y--;
        if(ss[idx]=='E' && x != tx) x++;
        if(ss[idx]=='W' && x != tx) x--;
        backtrack( x,y,idx+1, time+1);
    }else{
    	backtrack(x,y,idx+1, time+1);
    }
}

int main(){

    char c;
    cin >> t >> sx >> sy >> tx >> ty;
    check();
    fn= fs= fe=fw= 0;
    ss="";
    for(int i=0;i<t;i++){
        cin >> c;
        if(c=='N') fn = 1;
        if(c=='S') fs = 1;
        if(c=='E') fe = 1;
        if(c=='W') fw = 1;
        ss+= c;
    }

    if( (n && !fn) || (s && !fs) || (e && !fe) || (w && !fw) ){
            cout << "-1\n";
            return 0;
    }

    backtrack(sx,sy,0,0);
    if(r)
        cout << res << "\n";
    else
        cout << "-1\n";
    return 0;
}
