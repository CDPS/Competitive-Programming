#include <bits/stdc++.h>

using namespace std;

int a[100];
int g[100][100];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<long> a(n,0);
    vector < vector <long> > g( m, vector<long>(n));

    long aux;
    int best;

     for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%ld",&g[i][j]);

    for(int i=0;i<m;i++){
        aux=-1;
        for(int j=0;j<n;j++){
            if(g[i][j]>aux){
                aux=g[i][j];
                best=j;
            }
        }
        a[ best ]++;
    }

    aux=-1;
    for(int j=0;j<n;j++){
        if(a[j]>aux){
            aux=a[j];
            best=j;
        }
    }
    printf("%d\n",best+1);
    return 0;
}
