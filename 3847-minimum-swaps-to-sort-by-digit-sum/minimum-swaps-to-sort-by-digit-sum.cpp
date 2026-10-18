class Solution {
public:
    int digSum(int n) {
        int sum = 0;

        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> afterSorted(nums);

        auto lambda = [this](int num1, int num2) {
            int num1S = digSum(num1);
            int num2S = digSum(num2);

            if (num1S != num2S) {
                return num1S < num2S;
            }

            return num1 < num2;
        };

        sort(afterSorted.begin(), afterSorted.end(), lambda);

        unordered_map<int, int> valToIdx;

        for (int i = 0; i < n; i++) {
            valToIdx[nums[i]] = i;
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            int exp = afterSorted[i];
            int curr = nums[i];

            if (exp == curr) {
                continue;
            }

            int idx = valToIdx[exp];

            swap(nums[i], nums[idx]);

            valToIdx[curr] = idx;
            valToIdx[exp] = i;

            count++;
        }

        return count;
    }
};