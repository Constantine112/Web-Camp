#pragma once
#include "stdio.h"
#include "stdlib.h"
//声明结构体
typedef char ElemType;
typedef struct StackNode {
	ElemType data;
	double data_1;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef enum Status {
	SUCCESS, ERROR
}Status;

typedef struct LinkStack {
	LinkStackPtr top;		//zhan ding zhi zhen
	int count;
}LinkStack;
//声明各种函数
/**********************************************************************************
Name............: Status push(LinkStack *head,ElemType e)
Description.....: 输入栈
Parameters......: head是栈的头，e是要输入的数
Return values...: 成功 return SUCCESS 失败-return ERROR
**********************************************************************************/
Status push(LinkStack *head, StackNode *e);
/**********************************************************************************
Name............: void destroyStack(LinkStack *head);
Description.....: 销毁栈
Parameters......: head是栈的头
Return values...:
**********************************************************************************/
void destroyStack(LinkStack *head);
/**********************************************************************************
Name............: Status clearStack(LinkStack *head);
Description.....: 清除栈
Parameters......: head是栈的头
Return values...: 成功 return SUCCESS 失败-return ERROR
**********************************************************************************/
Status clearStack(LinkStack *head);
/**********************************************************************************
Name............: int lengthStack(LinkStack *head)
Description.....: 栈的长度
Parameters......: head是栈的头
Return values...: 成功 返回 栈的长度，失败-return -1
**********************************************************************************/
int lengthStack(LinkStack *head);
/**********************************************************************************
Name............: LinkStack * initStack(void)
Description.....: 初始化栈
Parameters......:
Return values...: 成功 return头节点 失败-return NULL
**********************************************************************************/
LinkStack * initStack(void);
/**********************************************************************************
Name............: Status pop(LinkStack *head,ElemType *e);
Description.....: 出栈
Parameters......: head是栈的头，e是保存要出栈的数的指针
Return values...: 成功 return SUCCESS 失败-return ERROR
**********************************************************************************/
Status pop(LinkStack *head, StackNode **e);
/**********************************************************************************
Name............: LinkStackPtr getTop(LinkStack *head);
Description.....: 找到栈顶
Parameters......: head是栈的头
Return values...: 成功 return栈顶节点 失败-return NULL
**********************************************************************************/
LinkStackPtr getTop(LinkStack *head);
/**********************************************************************************
Name............: Status BackSpace(LinkStack *head)
Description.....: 回删
Parameters......: head是栈的头
Return values...: 成功 return SUCCESS 失败-return ERROR
**********************************************************************************/
Status BackSpace(LinkStack *head);
/**********************************************************************************
Name............: Status BackSpace(LinkStack *head)
Description.....: 判断是否为空ADT
Parameters......: head是栈的头
Return values...: 成功 return SUCCESS 失败-return ERROR
**********************************************************************************/
Status isEmpty(LinkStack *head);
/**********************************************************************************
Name............: Status BackSpace(LinkStack *head)
Description.....: 创建四则运算
Parameters......: head是栈的头
Return values...: 成功 return 栈顶 失败-return NULL
**********************************************************************************/
LinkStack* createL(void);
/**********************************************************************************
Name............: Status BackSpace(LinkStack *head)
Description.....: 显示四则运算
Parameters......: head是栈的头
Return values...:成功返回SUCCESS ，失败 return ERROR
**********************************************************************************/
Status calculate(LinkStack* head_1);