 #include <bits/stdc++.h>



int m[25][25];

int main(){

    int t;
    scanf("%d",&t);

    while(t--){

        int n;
        scanf("%d",&n);

        long r = n*(n+1)/2;

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){
                scanf("%d",&m[i][j]);
            }
        }

        int raiz = sqrt(n);

        bool res = true;

        for(int i=0;i<n;i++){

            long res1=0;
            long res2=0;

            for(int j=0;j<n;j++){
                    res1+=m[i][j];
                    res2+=m[j][i];
            }

            if(res1==r && res2==r){
                continue;
            }else{
                res=false;
                break;
            }
        }

        if(!res){
             printf("no\n");
            continue;
        }


        for(int i=0;i<n;i+=raiz){

           for(int j=0;j<n;j+=raiz){

                int res3=0;
                for(int k=0;k<raiz;k++){

                   for(int l=0;l<raiz;l++){
                        res3+=m[k+i][l+j];
                    }
                }
                if(res3==r)
                    continue;
                else{
                        res=false;
                        break;
                }
           }

        }

        if(res)
            printf("yes\n");
        else
            printf("no\n");

    }

    return 0;
}
