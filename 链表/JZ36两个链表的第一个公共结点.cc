// 链表公共节点，特点是先分支再合并，因此找合并前的链表长度差，再双指针
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution
{
public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        int len1 = 0;
        ListNode *p1 = pHead1;
        while (pHead1)
        {
            pHead1 = pHead1->next;
            len1++;
        }
        int len2 = 0;
        ListNode *p2 = pHead2;
        while (pHead2)
        {
            pHead2 = pHead2->next;
            len2++;
        }
        if (len1 < len2)
        {
            int skip = len2 - len1;
            while (skip--)
            {
                p2 = p2->next;
            }
        }
        else
        {
            int skip = len1 - len2;
            while (skip--)
            {
                p1 = p1->next;
            }
        }
        while (p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};