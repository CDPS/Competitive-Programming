class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size();
        int sumCost = 0, sumGas = 0;
        for(int i=0;i<n;i++)
            sumCost+= cost[i], sumGas+=gas[i];

        if(sumCost > sumGas)
            return -1;

        int current = 0, ans=0;
        for(int i =0;i<n;i++){
            current+=gas[i] - cost[i];
            if(current < 0 )
                current = 0 , ans = i +1;
        }
        return ans;
    }
};