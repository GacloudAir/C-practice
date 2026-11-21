#include <vector>
using namespace std;

class Solution {                            //本题较简单,主要考察数组指针的使用,因为不能同时对调,需要加入一个小缓冲区
public:
    void reverseString(vector<char>& s) {
        int l = 0;
        int r = s.size()-1;
        while(l<r)
        {
            char n = s[l];
            s[l] = s[r];
            s[r] = n;
            l++;
            r--;
        }
    }
};

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    Solution().reverseString(s);
    return 0;
}