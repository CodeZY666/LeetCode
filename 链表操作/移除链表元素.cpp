/*
problem:删除链表中等于给定值 val 的所有节点。
data:2026/3/6
Author by:ZY
*/
/*
假设现在有一个链表：head -> [1 | next] -> [2 | next] -> [6 | next] -> [3 | next] -> NULL
假设每个节点的地址分别为：
节点1（值1）：0x1000，next = 0x2000
节点2（值2）：0x2000，next = 0x3000
节点6（值6）：0x3000，next = 0x4000
节点3（值3）：0x4000，next = 0x0
头指针 head 是一个指针变量，它存放的是第一个节点的地址 0x1000。

指针变量与成员访问：
cur 也是一个指针变量，开始时 cur = head，所以 cur 的值是 0x1000。
cur->next 的意思是：从 cur 存储的地址（0x1000）出发，找到该地址对应的内存块，然后取出它的 next 成员。因为 next 成员在节点中的偏移是固定的（假设编译后 next 在节点内偏移 4 字节），
所以实际上 cur->next 就是读取地址 0x1000 + 4 处存放的值，即 0x2000。
cur->next->next 先取得 cur->next 的值（0x2000），然后以它为地址，找到节点2，再读取其 next 成员（即地址 0x2000 + 4 处的值），结果是 0x3000

删除操作的内存视角
现在我们要删除所有值为 6 的节点。假设当前 cur 指向节点2（地址 0x2000），我们要删除的下一个节点（节点6，地址 0x3000）的值等于 6。
执行 ListNode* tmp = cur->next;
这行将 cur->next 的值（即 0x3000）赋给指针变量 tmp。现在 tmp 也指向节点6。
目的是暂时保存待删除节点的地址，以便后面释放内存。

执行 cur->next = cur->next->next;
等号右边 cur->next->next 的值是 0x4000（节点3的地址）。
等号左边 cur->next 是节点2的 next 成员所在的内存位置（地址 0x2000 + 4）。
赋值操作：将 0x4000 写入到节点2的 next 成员中。
现在节点2的 next 直接指向节点3，跳过节点6。

删除前内存布局（简化）：
cur (0x2000) -> 节点2 [val=2 | next=0x3000]
节点6 [val=6 | next=0x4000]
节点3 [val=3 | next=0x0]

删除后内存布局：
节点2 [val=2 | next=0x4000]  // 注意这里 next 变了
节点6 [val=6 | next=0x4000]  // 节点6仍然存在，但已不在链表中
节点3 [val=3 | next=0x0]
*/
class Solution{
public:
    ListNode* removeElements(ListNode* head, int val){
        // 删除头节点
        while(head != NULL && head->val == val){
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }

        // 删除非头节点
        ListNode* current = head;
        while(current != NULL && current->next != NULL){
            if(current->next->val == val){
                ListNode* tmp = current->next;
                current->next = current->next->next;
                delete tmp;
            }else{
                current = current->next; // 只有当当前节点的下一个节点不需要删除时，才移动到下一个节点
            }
        }
        return head;
    }
};
