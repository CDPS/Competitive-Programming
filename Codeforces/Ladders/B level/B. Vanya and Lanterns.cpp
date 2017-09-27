#include <bits/stdc++.h>

using namespace std;

vector <long> v;
long length;


bool f(double radius){

    if(double(v[0])-radius>0.0) return 0;

    for(int i=1;i<v.size();i++)
        if( !( double(v[i-1])+radius >= double(v[i])-radius) )
            return 0;

    if( double(v[v.size()-1])+radius<length) return 0;

    return 1;
}

double binarySearch(){
    double l =0, h = length,m;
    int it=1000;
    while(it--){
        m =  l + ( (h-l)/2.0 );
        if(f(m)) h = m;
        else l = m;
    }
    return m;
}

int main(){

    int n;
    scanf("%d %ld",&n,&length);

    v = vector<long>(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());
    printf("%.9lf",binarySearch());
    return 0;
}
