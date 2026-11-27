#include <iostream>
using namespace std;

// 链表节点定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {//本题需注意对调前后的防断链,越多节点参与需要处理的节点越多;
        //此外,需要防止出边界的判断也越多
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pt0 = dummy;
        ListNode* pt1;
        ListNode* pt2;
        while(pt0->next != nullptr && pt0->next->next != nullptr)//提前判断终止条件,防止出现问题
        {
            pt1 = pt0->next;
            pt2 = pt1->next;
            pt0->next = pt2;//0->2
            pt1->next = pt2->next;//1->3
            pt2->next = pt1;//2->1
            //0+2x->2+2x->1+2x
            pt0 = pt1;
        }
    return dummy->next; 
    }
};

int main() {
    // 构建测试链表: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution sol;
    ListNode* res = sol.swapPairs(head);

    // 打印结果
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl; // 期望输出: 2 1 4 3

    return 0;
}