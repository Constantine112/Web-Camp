#include "stdafx.h"
#include "stackADT.h"
ptr_Node create(int *arr, int n){					//创建链表
	Node *p1 , *p2, *head;
	if( (head=(Node*)malloc(sizeof(Node))) && head == NULL) return NULL;			//判断是否能分配空间
	p1 = p2 = head;
	for(int i = 0;i < n;i++){
		if(i >= 1)									
			p2 = p1;
		p1->data=arr[i];
		if(( p1 = (Node*)malloc(sizeof(Node))) && p1==NULL ) {				//再一次判断是否有空间分配
			destroy(head);	
			return NULL;
		}
		p2->next = p1;

	}
	p2->next = NULL;
	free(p1);	
	return head;	
}
Status delete_(ptr_Node *head, int index, int *data){
	if(index<0) {
		printf("ERROR\n");
		return ERROR;
	}
	if (*head != NULL){								//判断是否有head				
		Node* p,*p1;
		p =* head;
		if(0==index){
			p1=p;
			*head=p->next;
			
			*data=p->data;
			free(p);
			return SUCCESS;
		}
		if(1==index){
			p1=p->next;
			p->next=p1->next;
			*data=p1->data;
			free(p1);
		
		
		return SUCCESS;
		}
		if(index<0){
			printf("the index is small,can't delete it");
			return ERROR;
		}
		
		for(int i = 1;i < index;i++){				//遍历链表到指定位置
			p = p->next;	
			if(p->next == NULL)
				{
					printf("the index is large,can't delete it");
					return ERROR;
				
				}
		}
		
			
			p1 = p->next;
			p->next = p->next->next;				//删除链表中的节点
			*data = p1->data;
			free(p1);
			return SUCCESS;
		
	}
	else {	
		printf("the head is none");
		return ERROR;
	}
	
} 
void destroy(ptr_Node head){						//销毁链表的函数
	if (head != NULL){
		ptr_Node p;
		while(head != NULL){
			p = head;
			head = head->next;
			free(p);
		}
	}
}
Status edit(ptr_Node head, int index, int *data){
	if(index<0) {
		printf("ERROR\n");
		return ERROR;
	}
	if (head!=NULL){										//判断是否有head	
		Node *p;
	p = head;
	int t;
	if(head->next == NULL && index == 1) return ERROR;			//判断是否只有一个节点
	if(index==0)
	{
		t = p->data;
		p->data = *data;
		*data = t;
		return SUCCESS;
	}
	for(int i = 1;i < index;i++){
			p = p->next;										//遍历链表寻找节点
			if(p->next == NULL)
				{
					printf("the index is large,can't delete it");
					return ERROR;
				
				}
		}
	
	t = p->next->data;						//修改节点的值
	p->next->data = *data;
	*data = t;
	return SUCCESS;
	}
	else {	
		printf("the head is none");
		return ERROR;
	}
}
Status insert(ptr_Node *head, ptr_Node node, int index){
	if(index<0) {
		printf("ERROR\n");
		return ERROR;
	}
	if ( *head == NULL ) return ERROR;				//判断是否有链表
	Node* p;								
	p=*head;
	if( index == 1 ){							//判断当index=1时的情况
		node->next = p->next;
		
		p->next = node;
		
		return SUCCESS;
	}
	if( 0==index){
		*head=node;
		
		node->next=p;
		
		return SUCCESS;
	}
	for (int i = 1 ; i < index ; i++){					//遍历指针找到节点
		p = p->next;
			if(p == NULL)
			{
				printf("the index is large,can't insert it");
				return ERROR;
			}
		}

	node->next = p->next;							//插入节点
		
		p->next = node;
		
	return SUCCESS;
	
}
void print(ptr_Node head){		//输出链表
	ptr_Node p;
	p = head;
	int i = 0;
	while(p != NULL){
	printf("%10d",p->data);
	p = p->next;
	i++;
	if(i == 5){
		printf("\n");
		i = 0;
	}
	}
	printf("\n");
}
int search(ptr_Node head, int data){		
	if (head == NULL) return -1;				//判断是否有链表
	Node *p;
	p =  head;
	int i = 1;
	if(head->data == data)				//判断头节点的值是否为data
		return 0;
	while(p->next != NULL){					//遍历链表找到data的值
		if(data == p->next->data)
			return i;
		p=p->next;
		i++;
	}
	return -1;
}
Status sort(ptr_Node *head){			//排序链表
	ptr_Node p,t;
	int min,j;
	t = p = *head;
	min = p->data;
	if(*head == NULL || p->next == NULL)
		return ERROR;
	
	while(t->next != NULL){
		while(p != NULL){
			if(min>p->data){
				j = min;
				min = p->data;
				p->data = j;
			}
			p = p->next;
		}
		t->data = min;
		t = p = t->next;
		min = t->data;
	}
	return SUCCESS;
}