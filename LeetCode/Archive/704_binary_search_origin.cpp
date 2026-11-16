#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();//隐式转换存在风险,最好触发强制转换
        if (n == 0) return -1;
        int left = 0;int right = n-1;
        while(left<=right)
        {   
            int mid = right+(left-right)/2;
            if (nums[mid]>target) {right = mid;mid = (left+mid)/2;}//每次循环开始自动重设mid,是冗余内容
            else if (nums[mid]<target) {left=mid;mid = (mid+right)/2;}//left/right的位置固定时,容易出现相邻数不能取新值,导致死循环
            else return mid;
        }
        return -1;
        }
};

int main() {
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    Solution s;
    cout << s.search(nums, target) << endl;
    return 0;
}