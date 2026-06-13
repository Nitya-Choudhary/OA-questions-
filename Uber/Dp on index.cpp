class Solution {
public:

    vector<int> p;

    long long dp[205][21][21][21];

    long long solve(int i,int x,int y,int z){

        if(i >= p.size())
            return 0;

        long long &ans = dp[i][x][y][z];

        if(ans != -1)
            return ans;

        ans = solve(i+1,x,y,z);

        if(x > 0){
            ans = max(ans,
                (long long)p[i]
                + solve(i+1,x-1,y,z));
        }

        if(y > 0 && i+1 < p.size()){
            ans = max(ans,
                (long long)p[i]
                + p[i+1]
                + solve(i+2,x,y-1,z));
        }

        if(z > 0 && i+2 < p.size()){
            ans = max(ans,
                (long long)p[i]
                + p[i+1]
                + p[i+2]
                + solve(i+3,x,y,z-1));
        }

        return ans;
    }

    long long maximizeDriverEarnings(
        vector<int>& rideProfits,
        int x,
        int y,
        int z
    ) {

        p = rideProfits;

        memset(dp,-1,sizeof(dp));

        return solve(0,x,y,z);
    }
};
