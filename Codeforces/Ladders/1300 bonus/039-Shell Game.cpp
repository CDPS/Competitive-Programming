#include <bits/stdc++.h>

using namespace std;

int a[4];

int main(){

    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);

    int index, swap_a, swap_b ;

    cin >> index;
    a[index] = 1;

    cin >> swap_a >> swap_b;
    swap(a[swap_a], a[swap_b]);
    cin >> swap_a >> swap_b;
    swap(a[swap_a], a[swap_b]);
    cin >> swap_a >> swap_b;
    swap(a[swap_a], a[swap_b]);

    int i=0;
    for(;i<4;i++)
        if(a[i])
            break;
    cout << i << "\n";
    return 0;
}
