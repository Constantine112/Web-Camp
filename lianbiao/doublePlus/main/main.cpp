// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "adts.h"
#include "claim.h"
#define MAX 10



extern Status insert_T(ptr_TNode *head, ptr_TNode node, int index);
int main(int argc, char* argv[])
{	int* k,m;
	TNode *p,*head;			
	Status t;
	printf("              ---------double link plus------------\n");
	printf("_______________________________________________________\n");
	printf("               ===============================        \n");
	printf("                     1.create lian biao \n");
	printf("                     2.explan the demo\n");
	printf("                     3.quit\n");
	printf("               ===============================\n");
	printf("________________________________________________________\n");
	printf("please enter your choice:");
	scanf("%d",&m);
	while(1){
	if(1==m){
		k = (int*)malloc(sizeof(int));					//创建int型指针	
		head = p = product();
		break;
	}
	if(2==m){
		printf("There are 2 functions\n");
		printf("1.delete:delete one point");
		printf("2.insert one an other");
		printf("please enter your choice:");
	scanf("%d",&m);
	}
	if(3==m){
		return 0;
	}
	}
	printf("There are 2 functions\n");					//选择功能
	printf("1.delete\t2.insert\t3.quit\n");
	printf("what function your want to use 1-3:\n");
	scanf("%d",&m);
	while(m != 3){
		if( m > 3 || m < 1 ){							
			printf("please enter again:");
			scanf("%d",&m);
			continue;
		}
		if( 1 == m ){							//选择删除功能
			
			while(p != NULL){
				printf("%d\t",p->data);
				p = p->next;
			}
			printf("\n");
			p=head;
			int i=0;
			while(p != NULL){
				printf("%d\t",i++);
				p=p->next;
			}
			p=head;
			printf("\n");
			printf("where position your want to delete:");
			scanf("%d",&i);
			t = delete_T(&p,i,k);
			head=p;
		}
		if( 2 == m ){
			while(p != NULL){
				printf("%d\t",p->data);
				p = p->next;
			}
			printf("\n");
			p=head;
			int i=0;
			while(p != NULL){
				printf("%d\t",i++);
				p=p->next;
			}
			p=head;
			printf("\n");
			ptr_TNode l;
			printf("create a table,enter the number:");			//选择插入
			l = (TNode*)malloc(sizeof(TNode));
			scanf("%d",&l->data);
			
			printf("where position your want to insert:");
			scanf("%d",&i);
			t = insert_T(&p,l,i);
			head=p;
		}
		if(t == SUCCESS){
		while(p != NULL){
		printf("%d\t",p->data);
		p = p->next;}
		}
		printf("\n");
		p=head;
		printf("what function your want to use 1-3:\n");
		scanf("%d",&m);
	}



	while(p != NULL){
		printf("%d\t",p->data);
		p = p->next;}
	printf("\n");
	printf("Thank for ueing\n");
	free(k);
	destroy(head);
	return 0;
}
void destroy(ptr_TNode head){						//销毁链表的函数
	if (head != NULL){
		ptr_TNode p;
		while(head != NULL){
			p = head;
			head = head->next;
			free(p);
		}
	}
}

