#include <bits/stdc++.h>

using namespace std;

char m[101][101];


int main(){

    int k;
        while(scanf("%d",&k)==1){

            double raiz= k*sqrt(2);
			int p= (int)raiz;

			int l= 4*k +1;

            for(int i=0;i<l;i++){
				for(int j=0;j<l;j++){
					m[i][j]=' ';
				}
			}

			for(int i=0;i<l;i++){
				m[k][i]='*';
				m[l-k-1][i]='*';
				m[i][l-k-1]='*';
				m[i][k]='*';
			}

			for(int i=0;i<p*2;i++){
				m[i][k+i]='*';
				m[i][l-k-1-i]='*';

				m[l-1-i][k+i]='*';
				m[l-1-i][l-k-1-i]='*';

				m[k+i][i]='*';
				m[l-k-1-i][i]='*';

				m[k+i][l-1-i]='*';
				m[l-k-1-i][l-1-i]='*';
			}

			for(int i=0;i<l;i++){
                string t="";
				for(int j=0;j<l;j++){

				    if(m[i][j]=='*'){
						t+="*";
						cout << t;
						t="";
					}else{
						t+=m[i][j];
					}

				}
				cout << endl;
			}
    }

    return 0;
}
