
#include "stdafx.h"
#include "stack.h"
LinkStack * initStack(void){
	LinkStack *head;
	head=(LinkStack *)malloc(sizeof(LinkStack));
	if ( head == NULL ) return NULL; 
	head->top=NULL;
	head->count=-1;
	return head;
}
Status push(LinkStack *head,ElemType e){
	if(head==NULL) return ERROR;
	if(e=='\n') return SUCCESS;
	StackNode* p1;
	p1=(StackNode*)malloc(sizeof(StackNode));
	if(p1==NULL) return ERROR;
	p1->data=e;
	if(head->count==-1){
		p1->next=NULL;
		head->count++;
		head->top=p1;
		return SUCCESS;
	}
	p1->next=head->top;
	head->top=p1;
	head->count++;
	return SUCCESS;
}
void destroyStack(LinkStack *head){
	StackNode *p,*p1;
	p=head->top;
	while(p){
		p1=p;
		p=p->next;
		free(p1);
	}
	free(head);
}
Status clearStack(LinkStack *head){
	if(head==NULL) return ERROR;
	StackNode *p,*p1;
	p=head->top;
	while(p){
		p1=p;
		
		p=p->next;
		free(p1);
		
	}
	head->top=NULL;
	head->count=-1;
	return SUCCESS;	
}
Status pop(LinkStack *head,ElemType *e){
	if(head==NULL||head->top==NULL) return ERROR;
	StackNode* p1;
	p1=head->top;
	head->top=head->top->next;
	*e=p1->data;
	free(p1);
	head->count--;
	return SUCCESS;
}
Status isEmpty(LinkStack *head){
	if(head==NULL||head->top==NULL) return ERROR;
	return SUCCESS;
}
LinkStackPtr getTop(LinkStack *head){
	if(head==NULL) return NULL;
	return head->top;
}
Status BackSpace(LinkStack *head){
	if(head==NULL) return ERROR;
	if(head->top==NULL) return SUCCESS;
	StackNode* p1;
	p1=head->top;
	head->top=head->top->next;

	free(p1);
	head->count--;
	return SUCCESS;
}