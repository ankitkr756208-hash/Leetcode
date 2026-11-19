class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n+1,0);
        for(int i=0;i<n;i++){
            ans[nums[i]]=1;
        }
        for(int i=0;i<n+1;i++){
            if(ans[i]==0) return i;
        }
        return -1;
    }
};