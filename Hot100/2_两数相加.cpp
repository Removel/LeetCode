/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
	public:
		ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
			ListNode *dummy = new ListNode (0);//虚拟头指针，析构函数第二个调用
			ListNode *current = dummy;//声明当前节点指针=头指针指向节点
			int carry = 0;//进位使用的数字
			while (l1 != nullptr || l2 != nullptr || carry != 0) {
				int sum = carry;
				if (l1 != nullptr) {
					sum += l1->val;
					l1 = l1->next;
				}
				if (l2 != nullptr) {
					sum += l2->val;
					l2 = l2->next;
				}
				carry = sum / 10;//更新进位的数字
				current->next = new ListNode(sum % 10);//第一次时因为是虚拟头指针，在第一次使用时next节点才是第一个节点
				current = current->next;//将current节点更新为current节点next指针指向的下一个节点
			}
			ListNode *result = dummy->next;//释放虚拟头节点的同时接入result的头指针即答案所需的链表头指针
			delete dummy;
			return result;
		}
};