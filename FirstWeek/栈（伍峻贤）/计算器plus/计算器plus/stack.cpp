#include "stdafx.h"
#include "stack.h"
LinkStack * initStack(void) {
	LinkStack *head;
	head = (LinkStack *)malloc(sizeof(LinkStack));
	if (head == NULL) return NULL;
	head->top = NULL;
	head->count = -1;
	return head;
}
Status push(LinkStack *head, StackNode *e) {
	if (head == NULL) return ERROR;
	if (e == NULL) return ERROR;



	if (head->count == -1) {
		e->next = NULL;
		head->count++;
		head->top = e;
		return SUCCESS;
	}
	e->next = head->top;
	head->top = e;
	head->count++;
	return SUCCESS;
}
void destroyStack(LinkStack *head) {
	StackNode *p, *p1;
	p = head->top;
	while (p) {
		p1 = p;
		p = p->next;
		free(p1);
	}
	free(head);
}
Status clearStack(LinkStack *head) {
	if (head == NULL) return SUCCESS;
	StackNode *p, *p1;
	p = head->top;
	while (p) {
		p1 = p;

		p = p->next;
		free(p1);

	}
	head->top = NULL;
	head->count = -1;
	return SUCCESS;
}
Status pop(LinkStack *head, StackNode **e) {
	if (head == NULL || head->top == NULL) return ERROR;
	StackNode* p1;
	p1 = head->top;
	head->top = head->top->next;
	*e = p1;

	head->count--;
	return SUCCESS;
}
Status isEmpty(LinkStack *head) {
	if (head == NULL || head->top == NULL) return SUCCESS;
	return ERROR;
}
LinkStackPtr getTop(LinkStack *head) {
	if (head == NULL) return NULL;
	return head->top;
}
Status BackSpace(LinkStack *head) {
	if (head == NULL) return ERROR;
	if (head->top == NULL) return SUCCESS;
	StackNode* p1;
	p1 = head->top;
	head->top = head->top->next;

	free(p1);
	head->count--;
	
	return SUCCESS;
}