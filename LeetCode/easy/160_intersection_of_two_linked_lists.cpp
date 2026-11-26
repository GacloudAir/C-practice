#include <iostream>
#include <cstddef> // 包含 NULL 的定义
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {//设链表格式为A->C和B->C,使用pA/pB走完后进入对方路线的方案,pA和pB相等时,
                //它们经过的总长为(A+B+C),刚好够双方走完并到达交点(如果没有C部分,走到的便是nullptr)
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pA = headA;
        ListNode* pB = headB;
        while(pA!=pB)
        {
            pA = (pA==nullptr)? headB : pA->next;
            pB = (pB==nullptr)? headA : pB->next;
        }
        return pA;
    }
};

int main() {
    // 1. 先创建两个链表【共用】的相交部分 (8 -> 4 -> 5)
    ListNode* commonNode8 = new ListNode(8);
    ListNode* commonNode4 = new ListNode(4);
    ListNode* commonNode5 = new ListNode(5);
    commonNode8->next = commonNode4;
    commonNode4->next = commonNode5;

    // 2. 构建链表 A 的前置部分 (4 -> 1)
    ListNode* headA = new ListNode(4);
    ListNode* a1 = new ListNode(1);
    headA->next = a1;
    a1->next = commonNode8; // 接到公共节点上

    // 3. 构建链表 B 的前置部分 (5 -> 6 -> 1)
    ListNode* headB = new ListNode(5);
    ListNode* b6 = new ListNode(6);
    ListNode* b1 = new ListNode(1);
    headB->next = b6;
    b6->next = b1;
    b1->next = commonNode8; // 接到公共节点上

    // 4. 测试你的函数
    Solution sol;
    ListNode* intersection = sol.getIntersectionNode(headA, headB);
    
    if (intersection != nullptr) {
        cout << "相交节点的值为: " << intersection->val << endl; // 应该输出 8
    } else {
        cout << "两个链表没有相交" << endl;
    }

    return 0;
}