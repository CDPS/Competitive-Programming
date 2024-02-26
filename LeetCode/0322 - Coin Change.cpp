class Solution {
public:

    int table[10001];
    int oo = 1000000;

    int coinChange(vector<int>& coins, int amount) {
    
        for(int i=1;i<=amount;i++)
            table[i] = oo;

        table[0] = 0;
        for(int i=0; i<coins.size(); i++)
            for(int j=coins[i]; j<=amount; j++)
                table[j]= min(1 + table[j-coins[i]],table[j]);
        
        return table[amount] == oo? -1: table[amount] ;
    }
};