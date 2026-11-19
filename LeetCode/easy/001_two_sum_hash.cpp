#include <vector>
#include <unordered_map>
using namespace std;

class Solution {        //本题最大的麻烦是暴力法的查找复杂度达到了O(n^2),考虑到我们可以记录查过的数并在遇到新数时比对
public:                 //哈希表查已有数非常高效(表内查找复杂度基本为O(1)),因此可以用哈希表存数据
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 1; int s = nums.size(); 
        unordered_map<int, int> need;
        need[target-nums[0]] = 0;
        while(i<s)
        {
            auto it = need.find(nums[i]);//先查后比较,减少运算量
            if (it != need.end())
            {
                return {it->second, i};
            }
            else
            {
                need[target-nums[i]] = i;
                i++;
            }
        }
    return{};
    }
};

int main()
{
    vector<int> nums = {2,7,11,15};
    int target = 9;
    Solution s;
    s.twoSum(nums, target);
    return 0;
}