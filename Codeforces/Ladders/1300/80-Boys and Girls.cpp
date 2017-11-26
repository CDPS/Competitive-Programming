#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream ci("input.txt");
    ofstream co("output.txt");

    int n,m;
    ci >> n >> m;

    string s="";
    if(n<m){
        for(int i=0;i<n;i++){
            s+="GB";
        }
        for(int i=0;i<m-n;i++){
            s+="G";
        }
    }
    else{
        for(int i=0;i<m;i++){
            s+="BG";
        }
        for(int i=0;i<n-m;i++){
            s+="B";
        }
    }
    co << s<<"\n";
    ci.close();
    co.close();
    return 0;
}
