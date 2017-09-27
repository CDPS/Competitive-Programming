#include <bits/stdc++.h>

using namespace std;

int main(){


    int t;
    scanf("%d",&t);

    int m,n;
    while(t--){
        scanf("%d %d",&m,&n);

        vector<vector<int> > v(m);

        int a;
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            v[ a % m ].push_back(a);
        }


        for( int i=0;i<m;i++){
                cout << i<<" -> " ;
                for(int j=0;j<v[i].size();j++){
                    cout <<v[i][j]<<" -> ";
                }
                cout<< "\\" << endl;
        }

        if(t!=0)
            cout<<endl;
    }
    return 0;
}
