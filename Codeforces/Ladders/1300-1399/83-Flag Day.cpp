#include <bits/stdc++.h>

using namespace std;

int a[100000][3];
int c[100000];

int main(){

    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++) c[i]=-1;

    for(int i=0;i<m;i++)
        scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);

    for(int i=0;i<m;i++){

         vector<int> v(3,0);
        for(int j=0;j<3;j++)
            if( c[a[i][j] -1]!=-1 ) v[  c[ a[i][j] -1 ] -1 ]=1;

        for(int j=0;j<3;j++){
             if( c[a[i][j] -1]==-1 ){
                    if(v[0]==0)     c[a[i][j] -1] =1,v[0]=1;
                    else if(v[1]==0)c[a[i][j] -1] =2,v[1]=1;
                    else c[a[i][j] -1] =3,v[2]=1;
             }
        }
    }

    for(int i=0;i<n;i++)
        printf("%d%s",c[i],(i==n-1)?"\n":" ");
    return 0;
}
