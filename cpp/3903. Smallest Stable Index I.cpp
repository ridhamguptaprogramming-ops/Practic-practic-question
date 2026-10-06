#include <iostream>
#include <stack>
using namespace std;

int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffixMin(n);
        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }
        int prefixMax = nums[0];
        for (int i = 0; i < n; i++) {
            prefixMax = max(prefixMax, nums[i]);
            if (prefixMax - suffixMin[i] <= k) {
                return i;
            }
        }
        return -1;
    }
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 3;
    int index = firstStableIndex(nums, k);
    cout << "Smallest Stable Index: " << index << endl;
    return 0;
}