class Solution {
private:
    int gpd(int n) {
        if ((n & 1) == 0)
        return n / 2;
        int i = 3;
        while (i * i <= n) {
            if (n % i == 0) {
                return n / i;
            }
            i = i + 2;
        }
        return 1;
    }

public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i + 1] >= nums[i]) {
                continue;
            }
            
            
            while (nums[i] > nums[i + 1]) {
                int g = gpd(nums[i]);
                cout << nums[i] << " ## " << g << endl;
                if (g == 1) {
                    return -1;
                }
                nums[i] /= g;
                ++ans;
            }
        }
        return ans;
    }
};
