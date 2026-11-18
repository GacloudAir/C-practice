//这份代码在存在多个需删除项会不满足要求,直接弃用
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if (n == 0) return 0;
        int *base = &nums[0]; 
        int *pt1 = base;
        int i = 0; int r = 0;int m =0;
        while(i<n)
        {
            int a = 0;
            if (*pt1 == val)
            {
                r++;
                int *pt2 = base+i+1;
                a = i+1;
                while(a<n){if (*pt2 != val)*pt1 = *pt2; pt2++; a++;}
            } 
            i++;
            pt1++;    
        }
        return (n-r);
    }
};

int main() {
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    Solution s;
    cout << s.removeElement(nums, val) << endl;
    return 0;
}