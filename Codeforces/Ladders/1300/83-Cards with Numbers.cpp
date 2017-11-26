#include <bits/stdc++.h>

using namespace std;


vector<int> g[5001];

int main(){

    FILE *arq = fopen("input.txt", "r");
    FILE *arqo = fopen("output.txt", "w");

    int n,ai;


    fscanf(arq, "%d", &n);

    for(int i=0;i<2*n;i++){
        fscanf(arq, "%d", &ai);
        g[ai].push_back(i+1);
    }

    for(int i=0;i<5001;i++){
        if(g[i].size()%2){
            fprintf(arqo, "-1\n");
            return 0;
        }
    }

    for(int i=0;i<5001;i++){
        for(int j=0;j<g[i].size();j+=2)
            fprintf(arqo,"%d %d\n",g[i][j],g[i][j+1] );
    }

    fclose(arq);
    fclose(arqo);
    return 0;
}
