/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

------------------------------------------------------------------------------------
//code

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int carry = 0;
        ListNode* retlist = new ListNode(0);
        ListNode* rettmp = retlist;
        while(p1 != NULL||p2 != NULL)
        {
            int x = (p1 != NULL) ? p1->val : 0;
            int y = (p2 != NULL) ? p2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            rettmp->next = new ListNode(sum%10);
            rettmp = rettmp->next;
            if(p1 != NULL)
                p1 = p1->next;
            if(p2 != NULL)
                p2 = p2->next;
        }
        if(carry == 1)
        {
            rettmp->next = new ListNode(1);
        }
        return retlist->next;
    }
};
