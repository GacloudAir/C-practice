#include <iostream>
#include <vector>
using namespace std;

struct ListNode 
{   
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *prev = dummy;//一个链表节点A得到了另一个节点B的地址,则同时得知A->next(即B->next);
        while (prev->next != nullptr)
        {
            if (prev->next->val == val)//检查到目标节点,先往后看一步排除,还要检查后面的后面;
            {
                prev->next = prev->next->next;
            }
            else//目光所及的点没有目标节点,向前走"一步"(实际上加上了排除的点的步数)
            {
                prev = prev->next;
            }
        }
        return dummy->next;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);
    Solution s;
    ListNode* res = s.removeElements(head, 6);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}