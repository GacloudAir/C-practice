
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = (int)nums.size();         //利用快慢指针,读写分离又通过r紧密联系,实现低时间复杂度,稳定的代码
        int i = 0; int r = 0;             //具体来说,遇到目标数就将写的目标左移一位(r++;nums[i-r])
        while (i < n) {                   //而遇到可用于写入的非目标数就进行写入
            if (nums[i] == val) {         //可以处理重复目标数(r增大而i-r不变)
                r++;                      // 又见一个 val，写入位置左移一格
            } else {
                nums[i - r] = nums[i];    // 非 val 元素向前挪 r 格
            }
            i++;
        }
        return (n - r);
    }

};

int main() {
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    Solution s;
    cout << s.removeElement(nums, val) << endl;
    return 0;
}