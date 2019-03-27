class Solution:
    def addTwoNumbers(self, l1, l2):
        add = l1.val + l2.val
        carry = add // 10
        add = add - 10 * carry
        head = ListNode(add)
        tail = head
        while (l1.next and l2.next):
            l1 = l1.next
            l2 = l2.next
            add = l1.val + l2.val + carry
            carry = add // 10
            add = add - 10 * carry
            tail.next = ListNode(add)
            tail = tail.next
        
        while (l1.next):
            l1 = l1.next
            add = l1.val + carry
            carry = add // 10
            add = add - 10 * carry
            tail.next = ListNode(add)
            tail = tail.next
           
        while (l2.next):
            l2 = l2.next
            add = l2.val + carry
            carry = add // 10
            add = add - 10 * carry
            tail.next = ListNode(add)
            tail = tail.next
            
        if (carry):
            tail.next = ListNode(1)
            tail = tail.next
            
        return head