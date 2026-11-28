#include <iostream>
#include <cstddef>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast==slow) break;
        }
        if (fast == nullptr || fast->next == nullptr) return nullptr;
        else 
        {
            fast = head;
            while (fast != slow)
            {
                slow = slow->next;
                fast = fast->next;
            }
            if (!fast) return nullptr;
            else return fast;
            
        }
    }
};

int main() {
    // 构造带环链表：3 -> 2 -> 0 -> -4 -> (回到 2)
    ListNode* head = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node0 = new ListNode(0);
    ListNode* nodeMinus4 = new ListNode(-4);
    
    head->next = node2;
    node2->next = node0;
    node0->next = nodeMinus4;
    nodeMinus4->next = node2; // 制造环，入口为 node2

    Solution sol;
    ListNode* entrance = sol.detectCycle(head);
    
    if (entrance != nullptr) {
        cout << "环的入口节点值为: " << entrance->val << endl; // 应该输出 2
    } else {
        cout << "无环" << endl;
    }

    return 0;
}