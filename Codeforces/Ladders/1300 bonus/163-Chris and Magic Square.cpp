#include <bits/stdc++.h>

using namespace std;

long a[500][500];

int main(){

    bool isD1 = false, isD2 = false;
    long long n,ex,ey;
    cin >> n;

    if(n == 1){
        cout  << 1 << "\n";
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
            if(a[i][j]==0){
                ex = i;
                ey = j;
            }
        }
    }

    long long sum = -1;
    for(int i=0;i<n;i++){
        if(i!=ex){
            long long aux = 0;
            for(int j=0;j<n;j++) aux += a[i][j];
            if(sum == -1){ sum = aux; continue;}
            if(sum != aux ){ sum = -1; break; }
        }
    }

    if(sum != -1){
        for(int i=0;i<n;i++){
            if(i!=ey){
                long long aux = 0;
                for(int j=0;j<n;j++) aux += a[j][i];
                if(sum != aux ){ sum = -1; break; }
            }
        }
    }

    if(sum != -1){
        long long aux = 0;
        for(int i=0;i<n;i++){
            if( i != ex || i != ey){ aux += a[i][i];}
            else{ aux = sum; isD1 = true;break; }
        }
        if(aux != sum) sum = -1;
    }

    if(sum != -1){
        long long aux = 0;
        for(int i=n-1, j=0;i>= 0;i--, j++){
            if( i != ex || j != ey){ aux += a[i][j];}
            else{ aux = sum; isD2 = true;break; }
        }
        if(aux != sum) sum = -1;
    }

    if(sum != -1){
        long long auxH = 0;
        for(int i=0;i<n;i++){ auxH += a[ex][i];}
        long long auxV = 0;
        for(int i=0;i<n;i++){ auxV += a[i][ey];}
        long long auxD1 = (isD1)? 0 : auxH;
        for(int i=0;i<n && isD1;i++){ auxD1 += a[i][i];}
        long long auxD2 = (isD2)? 0 : auxH;
        for(int i=n-1, j=0;i>= 0 && isD2; i--, j++){ auxD2 += a[i][j]; }
        if(auxH + auxV + auxD1 + auxD2 == auxH*4){
            sum-=auxH;
        }else{
            sum = -1;
        }

        if(sum <= 0 )
            sum = -1;
    }

    cout << sum << "\n";
    return 0;
}
