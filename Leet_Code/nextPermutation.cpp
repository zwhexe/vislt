#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 0) return;
        int len = nums.size();
        int pos = len-1;
        // loop to update max pos and find smaller one 
        for(int i = len - 2; i >= 0; i--) {
            if(nums[i] >= nums[pos])
                pos = i;
            else
                break;
        }
        // exchange right place and pos-1
        int t = pos;
        if(pos != 0){
            for(int j = pos; j < len; j++) {
                if(nums[j] < nums[pos] && nums[j] > nums[pos-1])
                    t = j;
            }
            int tmp = nums[t];
            nums[t] = nums[pos-1];
            nums[pos-1] = tmp;

            // ascending pos to end
            quicksort(nums, pos, len - 1);
        }
        else{
            quicksort(nums, 0, len-1);
        }
    }

    void quicksort(vector<int>& nums, int start, int end) {
        // using quick sort
        if(start < end){
            int pivot = partition(nums, start, end);
            quicksort(nums, start, pivot-1);
            quicksort(nums, pivot+1, end);
        }
    }

    int partition(vector<int>& nums, int start, int end) {
        int pivot = nums[start];
        while(start < end) {
            while(start < end && pivot <= nums[end])
                end--;
            nums[start] = nums[end];
            while(start < end && pivot >= nums[start])
                start++;
            nums[end] = nums[start];
        }
        nums[start] = pivot;
        return start;
    }
};

int main()
{
    //vector<int> nums {1,2,3,4,6,5};
    vector<int> nums {1,3,2};
    Solution sol;
    sol.nextPermutation(nums);
    for(auto a: nums)
        cout << a << endl;

    return 0;
}