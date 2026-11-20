# STL 刷题速成手册

> 目标：用最短时间掌握 LeetCode 前 100 题所需的 STL 子集，不是成为 STL 专家。
> 适用：已学完 C++ 基础语法、指针、类，准备系统刷题的学习者。

---

## 0. 结论：别精读《C++ Primer Plus》的 STL 章节

**Prata 那本书的 STL 部分（ch16）对刷题性价比很低**，原因有三：

1. **内容偏旧**：重点讲 `auto_ptr`（C++11 已废弃、C++17 已删除）、`valarray` 等刷题几乎不用的东西。
2. **讲法偏理论**：它的定位是"介绍标准库存在什么"，不是"教你在算法题里怎么用"。你会花大量时间读不写代码。
3. **覆盖不全**：对刷题最关键的 `unordered_map` / `unordered_set`、复杂度、常用算法，讲得很浅。

**正确策略**：

| 需求 | 去哪 |
|---|---|
| 查某个容器/函数怎么用 | **cppreference 中文** https://zh.cppreference.com （权威，第一选择） |
| 按题目顺序刷题学 STL | **代码随想录** https://programmercarl.com （免费，C++ 主线，图文+视频） |
| 某个 API 到底什么意思 | 本手册 + cppreference |
| 深入理解 STL 源码/迭代器原理 | 以后再说，刷题阶段不需要 |

> 你的方向是**嵌入式/仪器**：固件里 STL 用得很少（资源受限、禁用异常/RTTI、静态分配为主），但**刷题和上位机（Qt）离不开**。所以目标是"熟练使用"，不是"研究实现"。

---

## 1. 万能骨架（每道题都长这样）

```cpp
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 返回值和参数由题目给定，只填函数体，不写 main
    int search(vector<int>& nums, int target) {
        ...
    }
};
```

三条铁律：
- **不写 `main()`**（本地调试时才加）
- 容器参数用**引用** `vector<int>&`，避免拷贝
- `auto` 能少写很多类型名：`auto it = nums.begin();`

---

## 2. vector（动态数组）— 出现率最高

**头文件**：`<vector>`

```cpp
vector<int> v;                      // 空
vector<int> v(10);                  // 10 个 0
vector<int> v(10, -1);              // 10 个 -1
vector<int> v = {1, 2, 3};          // 初始化列表
```

| 操作 | 写法 | 说明 |
|---|---|---|
| 元素个数 | `v.size()` | 返回 `size_t`（无符号），建议 `(int)v.size()` |
| 下标访问 | `v[i]` | O(1)，**不检查越界** |
| 尾部追加 | `v.push_back(x)` | 均摊 O(1) |
| 尾部删除 | `v.pop_back()` | 前提：非空 |
| 改长度 | `v.resize(n)` | 变长补 0，变短截断 |
| 判空 | `v.empty()` | 比 `size()==0` 快一点点 |
| 首/尾元素 | `v.front()` / `v.back()` | 前提：非空 |

```cpp
// 遍历三种写法
for (int i = 0; i < (int)v.size(); ++i) cout << v[i];  // 要下标
for (int x : v) cout << x;                              // 只要值（C++11）
for (int& x : v) x *= 2;                                // 要修改原元素，必须 &
```

**坑**：
- `v[v.size()]` 越界，合法下标是 `0 .. size()-1`（你在 27 题已经踩过 `&nums[n]` 的雷）
- 空 vector 不能 `v[0]` / `front()` / `back()`

---

## 3. string（字符串）

**头文件**：`<string>`

```cpp
string s = "hello";
```

| 操作 | 写法 | 说明 |
|---|---|---|
| 长度 | `s.size()` / `s.length()` | 完全等价 |
| 下标 | `s[i]` | 可读写，`char&` |
| 拼接 | `s += c;` / `s += "abc";` | |
| 子串 | `s.substr(pos, len)` | 从 pos 开始取 len 个字符 |
| 查找 | `s.find(c)` | 找到返回下标，找不到返回 `string::npos` |
| 比较 | `s == t` | 直接用，不用 strcmp |

```cpp
for (char c : s) { ... }             // 遍历每个字符
if (s.find('a') != string::npos) ... // 判断字符存在
```

**坑**：C++ 没有 `s[-1]`，最后一个字符是 `s[s.size()-1]`（空串会越界）。

---

## 4. unordered_map / map（哈希表）— 计数和查找神器

**头文件**：`<unordered_map>` / `<map>`

```cpp
unordered_map<int, int> mp;   // key -> value，查找平均 O(1)
map<int, int> om;             // 有序，查找 O(log n)，需要顺序时用
```

| 操作 | 写法 | 说明 |
|---|---|---|
| 插入/赋值 | `mp[key] = value;` | key 不存在会**自动创建** |
| 计数自增 | `mp[c]++;` | 不存在则创建并初始化为 0 再 ++ |
| 判存在 | `mp.count(key)` | 返回 0 或 1，**最安全** |
| 查找 | `auto it = mp.find(key);` | 找不到返回 `mp.end()` |
| 取键值 | `it->first` / `it->second` | pair 的键 / 值 |
| 删除 | `mp.erase(key)` | |

```cpp
// 两数之和（你做过的 001）
unordered_map<int, int> seen;              // 值 -> 下标
for (int i = 0; i < (int)nums.size(); ++i) {
    int need = target - nums[i];
    if (seen.count(need)) return {seen[need], i};
    seen[nums[i]] = i;
}
return {};

// 字母计数（242 题）
unordered_map<char, int> freq;
for (char c : s) freq[c]++;
```

**坑（重要）**：
- `mp[k]` 在 key 不存在时会**自动插入**默认值，污染表。判断存在必须用 `count()` 或 `find()`，**不要用 `if (mp[k])`**。
- `unordered_map` 平均 O(1)，最坏 O(n)；`map` 稳定 O(log n) 且有序。刷题优先 `unordered_map`。

---

## 5. set / unordered_set（集合）— 去重和存在性

**头文件**：`<set>` / `<unordered_set>`

```cpp
unordered_set<int> st;
st.insert(x);              // 插入
st.count(x);               // 存在？返回 0/1
st.erase(x);               // 删除
```

典型用途：数组交集、判断元素是否出现过。`unordered_set` 去重最方便：

```cpp
vector<int> unique(nums.begin(), nums.end());  // 若用 set 去重：
set<int> s(nums.begin(), nums.end());           // 有序且去重
```

---

## 6. algorithm（算法）— 必背的 6 个

**头文件**：`<algorithm>`

```cpp
sort(v.begin(), v.end());                       // 排序，默认升序
sort(v.begin(), v.end(), greater<int>());       // 降序（需 <functional>）
reverse(v.begin(), v.end());                    // 反转
int mx = *max_element(v.begin(), v.end());      // 最大值（返回迭代器，要解引用）
int mn = *min_element(v.begin(), v.end());
auto it = find(v.begin(), v.end(), x);          // 查找，找不到返回 v.end()
```

**迭代器**：`begin()` 指向第一个元素，`end()` 指向**尾后**（不是最后一个元素）。`*it` 取元素，`it++` 移到下一个。

```cpp
for (auto it = v.begin(); it != v.end(); ++it) cout << *it;
```

---

## 7. stack / queue（容器适配器）

**头文件**：`<stack>` / `<queue>`

```cpp
stack<int> st;
st.push(1);        // 入栈
st.top();          // 看栈顶（不弹出）
st.pop();          // 弹出（无返回值！）
st.empty();

queue<int> q;
q.push(1);         // 入队
q.front();         // 队首
q.pop();           // 出队（无返回值！）
```

**坑（高频）**：`pop()` 不返回元素。要先 `int x = st.top(); st.pop();`，不能写 `int x = st.pop();`。
你自己手写过 Stack/Queue，原理已经懂了，做题直接用 STL 的，别重复造轮子。

---

## 8. pair 与结构化绑定

```cpp
pair<int, int> p = {1, 2};
p.first;   // 1
p.second;  // 2

auto [a, b] = p;   // C++17 结构化绑定，直接拆成两个变量
```

`map` 的每次遍历拿到的就是 `pair<const Key, Value>`。

---

## 9. 两周补完计划（配合刷题）

| 天 | 内容 | 配套题目 |
|---|---|---|
| 1–2 | `vector` + 范围 for + 迭代器 | 704、27（重做一遍，用 STL 写法） |
| 3–4 | `string` 的 substr/find/[] | 344 反转字符串、387 唯一字符 |
| 5–7 | `unordered_map` / `unordered_set` + count/find | 001 两数之和、242 字母异位词、217 存在重复 |
| 8–9 | `algorithm`：sort/find/max_element | 977 有序数组的平方、1365 数组序号转换 |
| 10–11 | `stack` / `queue` | 20 有效的括号、体检析括号 |
| 12–14 | 综合复习，把前 8 题用 STL 重写 | 全部重做 |

**每天 1–1.5 小时即可**。学一个容器当天就做题，不要"学完再用"。

---

## 10. 常见坑速查

| 坑 | 说明 |
|---|---|
| `size()` 是 `size_t` | 与 `int` 混用会有警告，减法可能下溢，用 `(int)v.size()` |
| `[]` 不检查越界 | 合法下标 `0..size()-1` |
| `mp[k]` 自动插入 | 判存在用 `count()` / `find()` |
| `pop()` 无返回值 | stack/queue 都要先 top/front 再 pop |
| `end()` 是尾后 | 不能解引用 `*v.end()` |
| 引用 vs 值 | 遍历修改元素用 `int& x`，只读用 `const int& x` 或 `int x` |
| 头文件遗漏 | 用到什么 include 什么，别只靠 `bits/stdc++.h`（力扣能用，但工程里不行） |

---

## 11. 延伸资源

- **cppreference 中文**：https://zh.cppreference.com — 查 API 第一选择，带复杂度和示例
- **代码随想录**：https://programmercarl.com — 免费刷题路线，C++ 主线，按专题顺序刷
- **learncpp.com**：英文，讲得细，适合将来补现代 C++（智能指针、移动语义）
- **力扣题解区**：看高赞 C++ 解法，是学 STL 惯用法最快的方式
