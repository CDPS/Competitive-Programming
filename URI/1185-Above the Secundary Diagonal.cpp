#include <bits/stdc++.h>

using namespace std;


int main(){


    char s;
    cin >> s;

    double res=0;

    for (int i=0; i < 12;i++)
    {
        for (int j=0; j < 12; j++)
        {
            double aux;
            cin >> aux;

            if (i + j < 11)
            {
                res += aux;
            }
        }
    }

    cout << (s == 'S' ? res : res / 66) << '\n';

    return 0;
}
