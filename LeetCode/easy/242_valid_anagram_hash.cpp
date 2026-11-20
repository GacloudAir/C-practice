#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//本题依旧利用了高效的哈希表,这次进行的是哈希统计,在s中记录字符,在t中反向记录已有字符,只要能回到原点(哈希表为空),就说明符合要求
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> cp;
        int i = 0;int r = s.length();
        if (s.length() != t.length()) return false;
        while(i<r)
        {
            cp[s[i]]++;
            i++;
        }
        i = 0;
        while(i<r)
        {
            if (cp.find(t[i]) == cp.end() || cp[t[i]] == 0) return false;
            cp[t[i]]--;
            i++;
        }
        // 遍历哈希表中的每一个键值对 pair
        /*for (const auto& pair : cp) {
            // pair.first 是字符，pair.second 是次数
            if (pair.second != 0) {
                return false; // 只要有一个不是 0，直接返回 false
            }
        }
        return true; // 全零，说明匹配*/
        //实际上整段都不需要了,因为在限定了总长一致时,如果t中存在一种字符比s中的少,
        //那么s中有多出的字符,会导致某项提前减到0后还需要减被排除
        return true;
    }
};

int main() {
    Solution sol;
    string s = "anagram";
    string t = "nagaram";
    bool res = sol.isAnagram(s, t);
    cout << res << endl;
    return 0;
}