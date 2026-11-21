class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currs=0,maxs=INT_MIN;
        for(int i : nums){
            currs +=i;
            maxs=max(maxs,currs);
             if(currs <0){
            currs=0;
        }
        }
       
        return maxs;
    }
};