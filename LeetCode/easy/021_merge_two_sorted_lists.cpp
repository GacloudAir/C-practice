#include <iostream>
#include <vector>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {//本题需要理解头尾指针的作用:头指针给予新链表的锚点,
        //尾指针为新的节点落脚
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val > list2->val)
            {
                tail -> next = list2;
                tail = list2;
                list2 = list2 -> next;
            }
            else 
            {
                tail -> next = list1;
                tail = list1;
                list1 = list1 -> next;
            }
        }
        if (list1 != nullptr) tail -> next = list1;//只要一个链表的节点接完了,就把另一个链表的剩余节点(已知原链表已排列)
        else tail ->next = list2;
        return dummy->next;//这便是新链表的地址(链表的单向性,前面加什么都无所谓,只要给出后面的节点,表现上和没有前节点一致)
    }
};

int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    Solution s;
    ListNode* res = s.mergeTwoLists(list1, list2);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}