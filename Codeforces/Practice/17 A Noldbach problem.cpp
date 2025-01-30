#include <bits/stdc++.h>

using namespace std;

int n, k;
bool prime[2001];
unordered_set<int> nolbach;

void sieve(){

   for (int i = 2; i*i <= 2000; i++)
       if (!prime[i])
           for (int j = i*i ; j <= n; j += i)
               prime[j] = 1;

    int prev = 2;
    for(int i=3;i<=1000;i++){
       if(!prime[i]){
            if(!prime[prev + i + 1])
                nolbach.insert( prev + i + 1);
            prev = i;
        }
    }
}

bool solve(){
    int acc=0;
    for(int i=2;i<=n;i++)
        if(nolbach.count(i)) acc++;
    return acc >= k;
}

int main(){
    cin.sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    sieve();
    cout << (solve()? "YES" : "NO") << "\n";
    return 0;
}
