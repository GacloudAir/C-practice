#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int front = 0;int s = nums.size(); int behind = s-1;
        vector<int> square(s);
        int * pt = &square[s-1];
        while (front<=behind)
        {   
            int i = nums[front] * nums[front];
            int r = nums[behind] * nums[behind];
            if (i >= r)
            {
                *pt = i;
                front++;
            }
            else
            {
                *pt = r;
                behind--;
            }
            pt--;
        }
        front = 0;
        return square;
    }
};

int main()
{
    vector<int> nums = {-4,-1,0,3,10};
    Solution s;
    s.sortedSquares(nums);
    return 0;
}