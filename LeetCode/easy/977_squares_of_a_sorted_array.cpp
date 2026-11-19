#include <vector>
using namespace std;

class Solution {                //本题最大的陷阱是,虽然头尾元素都是在自己排列的极大值,但不一定是最大值,需要额外比较
public:                         //解决方法是每次只写一个当前最大值,然后比较剩余值
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