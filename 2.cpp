//2、两数相加
/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序的方式存储的，并且它们的每个节点只能存储一位数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/
//时间复杂度：O(max⁡(m,n))，假设m和n分别表示长度，上面的算法最多重复 max⁡(m,n)次。
//空间复杂度：O(max⁡(m,n))， 新列表的长度最多为 max⁡(m,n)+1
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * result = new ListNode(0);
        ListNode * curr = result;
        int temp=0,val1,val2;
        while(l1 != NULL || l2!=NULL){
            val1 = (l1!=NULL)?l1->val:0;
            val2 = (l2!=NULL)?l2->val:0;
            curr->next = new ListNode((val1+val2+temp)%10);
            curr = curr->next;
            temp = (val1+val2+temp)>=10?1:0;
            if(l1!=NULL) l1=l1->next;
            if(l2!=NULL) l2=l2->next;
        }
        if( temp == 1)
            curr->next = new ListNode(1);
        return result->next;  
    }
};
