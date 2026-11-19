class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        int totalSum = 0;

        for(int i = 0; i < n; i++) {
            totalSum += cardPoints[i];
        }
        int windowSize = n - k;
        if(windowSize == 0) {
            return totalSum;
        }

        int sum = 0;
        for(int i = 0; i < windowSize; i++) {
            sum += cardPoints[i];
        }

        int mini = sum;
        for(int i = windowSize; i < n; i++) {
            sum = sum - cardPoints[i-windowSize] + cardPoints[i];
            mini = min(mini, sum);
        }

        return totalSum - mini;
    }
};