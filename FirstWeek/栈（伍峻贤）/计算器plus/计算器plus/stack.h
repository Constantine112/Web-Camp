#pragma once
#include "stdio.h"
#include "stdlib.h"
//�����ṹ��
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
//�������ֺ���
/**********************************************************************************
Name............: Status push(LinkStack *head,ElemType e)
Description.....: ����ջ
Parameters......: head��ջ��ͷ��e��Ҫ�������
Return values...: �ɹ� return SUCCESS ʧ��-return ERROR
**********************************************************************************/
Status push(LinkStack *head, StackNode *e);
/**********************************************************************************
Name............: void destroyStack(LinkStack *head);
Description.....: ����ջ
Parameters......: head��ջ��ͷ
Return values...:
**********************************************************************************/
void destroyStack(LinkStack *head);
/**********************************************************************************
Name............: Status clearStack(LinkStack *head);
Description.....: ���ջ
Parameters......: head��ջ��ͷ
Return values...: �ɹ� return SUCCESS ʧ��-return ERROR
**********************************************************************************/
Status clearStack(LinkStack *head);
/**********************************************************************************
Name............: int lengthStack(LinkStack *head)
Description.....: ջ�ĳ���
Parameters......: head��ջ��ͷ
Return values...: �ɹ� ���� ջ�ĳ��ȣ�ʧ��-return -1
**********************************************************************************/
int lengthStack(LinkStack *head);
/**********************************************************************************
Name............: LinkStack * initStack(void)
Description.....: ��ʼ��ջ
Parameters......:
Return values...: �ɹ� returnͷ�ڵ� ʧ��-return NULL
**********************************************************************************/
LinkStack * initStack(void);
/**********************************************************************************
Name............: Status pop(LinkStack *head,ElemType *e);
Description.....: ��ջ
Parameters......: head��ջ��ͷ��e�Ǳ���Ҫ��ջ������ָ��
Return values...: �ɹ� return SUCCESS ʧ��-return ERROR
**********************************************************************************/
Status pop(LinkStack *head, StackNode **e);
/**********************************************************************************
Name............: LinkStackPtr getTop(LinkStack *head);
Description.....: �ҵ�ջ��
Parameters......: head��ջ��ͷ
Return values...: �ɹ� returnջ���ڵ� ʧ��-return NULL
**********************************************************************************/
LinkStackPtr getTop(LinkStack *head);
/**********************************************************************************
Name............: Status BackSpace(LinkStack *head)
Description.....: ��ɾ
Parameters......: head��ջ��ͷ
Return values...: �ɹ� return SUCCESS ʧ��-return ERROR
**********************************************************************************/
Status BackSpace(LinkStack *head);
/**********************************************************************************
Name............: Status BackSpace(LinkStack *head)
Description.....: �ж��Ƿ�Ϊ��ADT
Parameters......: head��ջ��ͷ
Return values...: �ɹ� return SUCCESS ʧ��-return ERROR
**********************************************************************************/
Status isEmpty(LinkStack *head);
/**********************************************************************************
Name............: Status BackSpace(LinkStack *head)
Description.....: ������������
Parameters......: head��ջ��ͷ
Return values...: �ɹ� return ջ�� ʧ��-return NULL
**********************************************************************************/
LinkStack* createL(void);
/**********************************************************************************
Name............: Status BackSpace(LinkStack *head)
Description.....: ��ʾ��������
Parameters......: head��ջ��ͷ
Return values...:�ɹ�����SUCCESS ��ʧ�� return ERROR
**********************************************************************************/
Status calculate(LinkStack* head_1);