class Solution {
public:

    bool dp[41];
    vector<vector<int>> result[41];

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        dp[0]=1;
        result[0] = { {} } ;        
        for(int i=0; i<candidates.size(); i++){
            for(int j=candidates[i]; j<=target; j++){
                dp[j] |= dp [ j - candidates[i] ];
                if( dp [ j - candidates[i] ] ){
                    vector<vector<int>> partial = result[ j - candidates[i]  ];

                    for(int k=0;k<partial.size();k++)
                        partial[k].push_back(candidates[i]);

                    result[j].insert( result[j].end(), partial.begin(), partial.end() );
                }
            }
        }

        return result[target];
    }
};