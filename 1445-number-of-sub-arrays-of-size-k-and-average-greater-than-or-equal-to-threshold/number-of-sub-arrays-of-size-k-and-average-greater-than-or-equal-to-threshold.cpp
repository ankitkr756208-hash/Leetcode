class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        int count=0;
        int sum=0;
        int end=0,st=0;
        for(int i=0;i<k;i++){
            sum +=arr[i];
        }
        float avg=sum/k;
        if(avg >=threshold) 
        count++;
        end=k;
        while(end<n){
            sum-=arr[st];
            sum +=arr[end];
            avg =sum/k;
            if(avg >=threshold) count++;
            end++;
            st++;
        }
        
        return count;

    }
};