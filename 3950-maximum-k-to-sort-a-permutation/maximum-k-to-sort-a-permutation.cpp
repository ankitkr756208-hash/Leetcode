class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans=-1;
        bool mis=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                ans &=nums[i];
                mis=true;
            }
        }
        return mis ? ans :0;
    }
};