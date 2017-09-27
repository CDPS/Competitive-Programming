#include <bits/stdc++.h>

using namespace std;

int main(){


    int n,m;

    stack<int> s1,s2;

    //ofstream co("rails.txt");

    bool first = true;
    while ( scanf("%d",&n) && n ){

        while(true){

            scanf("%d", &m);
            if(m==0)
                break;

            stack <int > s4;
            stack <int > s3;

            for(int i=0;i<n;i++){
                s3.push(n-i);
            }

            vector<int> v;
            v.push_back(m);

            for(int i=0;i<n-1;i++){
                scanf("%d", &m);
                v.push_back(m);
            }

            bool f =1;

           for(int i=0;i<n && f;i++){

                int p = v[i];

                if( !s3.empty() && p >= s3.top()){

                    while( !s3.empty() && s3.top()<=p){
                        s4.push(s3.top()); s3.pop();
                    }
                    s4.pop();
                    continue;
                }

                if( !s3.empty()  && !s4.empty() && p <s3.top() && p==s4.top()){ s4.pop(); continue;}

                if(!s4.empty() && p == s4.top())
                    s4.pop();
                else f=0;
            }

            if(f)cout << "Yes\n";
            else cout << "No\n";
        }
        cout << "\n";
    }
    return 0;
}
