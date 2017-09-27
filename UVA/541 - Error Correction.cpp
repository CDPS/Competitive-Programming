#include <bits/stdc++.h>

using namespace std;

int rows[100],columns[100], m[100][100];
int n,a;

bool check(){
    for(int i=0;i<n;i++)
        if(rows[i]%2!=0 || columns[i]%2!=0)
            return false;
    return true;
}

int main(){

    while(scanf("%d",&n) && n){

        for(int i=0;i<n;i++)
            columns[i]=rows[i]=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&a);
                m[i][j]=a;rows[i]+=a;columns[j]+=a;
            }
        }

        if(check())
            printf("OK\n");
        else{
            bool f=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(!m[i][j]){
                        columns[j]++;rows[i]++;
                        if(check()){
                            f=1;
                            printf("Change bit (%d,%d)\n",i+1,j+1);
                            break;
                        }
                        columns[j]--;rows[i]--;
                    }else{
                        columns[j]--;rows[i]--;
                        if(check()){
                            f=1;
                            printf("Change bit (%d,%d)\n",i+1,j+1);
                            break;
                        }
                        columns[j]++;rows[i]++;
                    }
                }
                if(f)break;
            }
            if(!f)
                printf("Corrupt\n");
        }
    }
    return 0;
}
