#include <bits/stdc++.h>

using namespace std;

bitset<10000001> m;
bitset<1001>an;
void sieve(int n){
    m.set();
    for(int i = 0;i<=n;i++)
        m[i]=1;
    m[0]=m[1]=0;

    for(int i=2;i*i<=n;i++){
        if(m[i]){
            for(int j=i+i;j<=n;j+=i)
                m[j]=0;
        }
    }
}

vector<int> getDigits(int n){
    vector<int> res;
    while(n>0){  res.push_back(n%10);  n/=10;  }
    return res;
}

int getNumber(vector<int> &n){
    int res=0; int m = n.size()-1;  int j=1;
    for(int i=m;i>=0;i--){
        res+= (n[i]*j);
        j*=10;
    }
    return res;
}

bool isAnagrammatic(int n){
    vector<int> d = getDigits(n);
    sort(d.begin(),d.end());
    do{
        int p = getNumber(d);
        if (!m[p]) return false;
    }while (next_permutation(d.begin(),d.end()));
    return true;
}

int main(){
    int n;
    sieve(1000);
    an.set(0);
    for(int i=3;i<=999;i+=2)
        if(m[i] && isAnagrammatic(i))
                an[i]=1;
    an[2]=1;
    while(true){
        scanf("%d",&n);
        if(n==0)
            break;

        if(n>=1000)
            printf("0\n");
        else{

            int l=1;
            int m = n+1;

            while(n){ n/=10; l*=10; };

            while(!an[m] && m<l)m++;

            if(an[m])
                printf("%d\n",m);
            else
                printf("0\n");
        }
    }
    return 0;
}

