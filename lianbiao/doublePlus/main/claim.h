/********************************************************************************************************************
Name.......................................:tatus delete_T(ptr_TNode *head, int index, int *data)
Description................................:删除某个节点
Parameters.................................: index-为节点位置，data-为保存删除节点值的指针，head炜链表头节点
Return value...............................:成功返回SUCCESS，失败返回ERROR
*********************************************************************************************************************/
Status delete_T(ptr_TNode *head, int index, int *data);			//双向链表,删除第 index 位节点后面的节点，将删除的结点的值保存到（*data）中 
/********************************************************************************************************************
Name.......................................:tatus delete_T(ptr_TNode *head, int index, int *data)
Description................................:在某个节点后面插入节点
Parameters.................................:index-要插入的节点的前一个节点位置，node-要插入的节点，head-链表头
Return value...............................:成功返回SUCCESS，失败返回ERROR
*********************************************************************************************************************/
Status insert_T(ptr_TNode *head, ptr_TNode node, int index);	//双向链表,在第 index 位后面插入 node 结点
																//插入成功返回 SUCCESS，失败返回 ERROR
/********************************************************************************************************************
Name.......................................:tatus delete_T(ptr_TNode *head, int index, int *data)
Description................................:生成链表
Parameters.................................:没有参数
Return value...............................:成功返回链表头，失败返回NULL
*********************************************************************************************************************/
TNode* product(void);
/********************************************************************************************************************
Name.......................................:void destroy(ptr_TNode head);
Description................................:xiao hui
Parameters.................................:没有参数
Return value...............................:none
*********************************************************************************************************************/
void destroy(ptr_TNode head);
