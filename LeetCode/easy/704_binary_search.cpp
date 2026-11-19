#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();//(类型)数据/类型(数据)均为强制类型转换的触发方式
        if (n == 0) return -1;
        int left = 0;int right = n-1;
        while(left<=right)
        {   
            int mid = right+(left-right)/2;//这行代码决定左/右端取平均值
            //原理:四则运算的同时会触发舍入规则(而不是加完了再说),若left与right之差为奇数,除完只舍不入,会把值的绝对值变小.
            //left＜right,所以是负数,实际上变大(右移);反之,用(right-left)/2得到正值,结果会变小(左移)
            //此外,不用(right+left)/2是因为如果left与right都非常大,使得left+right大于int上限,会导致数据溢出
            if (nums[mid]>target) right = mid-1;//冗余代码已清除
            else if (nums[mid]<target) left = mid+1;//右端左移,左端右移,在旧代码触发死循环的情况下再推一把
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