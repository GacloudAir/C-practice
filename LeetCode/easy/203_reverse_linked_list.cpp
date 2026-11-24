#include <iostream> 
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {//本题难度不高,但需要理解链表的意义.初值设定,中间缓存等都需要准备好
        ListNode *pre = nullptr;
        ListNode *curr = head;
        ListNode *temp;
        while(curr != nullptr)
        {
            temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }
        return pre;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution s;
    ListNode* res = s.reverseList(head);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}