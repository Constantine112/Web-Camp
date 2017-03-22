// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stackADT.h"



int main(int argc, char* argv[])
{	printf("\n");
	printf("		     ====================================  \n");
	printf("		    ||       输入 1 进入lianbiao        || \n");
	printf("		    ||       输入 2 看使用说明          || \n");
	printf("                    ||       输入 3 退出系统            || \n");
	printf("		     ====================================  \n\n\n");
	printf("\n--------------------------------------------------------------------------------\n");				
	printf("                                        \n");
	printf("      ~~^^~~                              \n");
	printf("     ^~^~~^~^                          \n");
	printf("     [o    o]                        \n");
	printf("     (	[]  )      --------------lianbiao-------------                      \n");
	printf("      { __ }                            \n");
	printf("       <~~>                             \n");
	printf("                                                                 @author:Con\n\n");                                      
	printf("--------------------------------------------------------------------------------\n");
	Node *p;
	int *a ,m , *l,number_1=0;
	Status t;
	ptr_Node *head;
	head=(ptr_Node *)malloc(sizeof(ptr_Node));
	l = (int*)malloc(sizeof(int));
	printf("please enter your choice:");
	scanf("%d",&m);
	while(1){
	if(1==m){
		l = (int*)malloc(sizeof(int));		//创建int型指针	
		printf("please enter the num to create the shu zu(-1 to end ):");
		scanf("%d",&m);
		while(m != -1){
			if(number_1  ==  0){
				a=(int*)malloc(sizeof(int));
			}
			else{
				a=(int*)realloc((void*)a,(number_1+1)*sizeof(int));
			}
				a[number_1]=m;
				number_1++;
				scanf("%d",&m);
		}
		printf("%d\n",number_1);
		*head = p = create(a,number_1);
		number_1=0;
		break;
	}
	if(2==m){
		printf("There are 2 functions\n");
		printf("1.delete:delete one point\t");
		printf("2.insert:insert one an other\n");
		printf("3.destory:destory lian biao\t ");
		printf("4.edit:chang number\n");
		printf("5.search:search NUmber\t\t");
		printf("6.sort:sort number\n");
		printf("7.print:printf\n");
		printf("please enter your choice:");
		scanf("%d",&m);

	}
	if(3==m){
		return 0;
	}
	}
	printf("There are 6 functions\n");
	printf("1.destory\t2.delete\t3.search\n4.edit\t\t5.sort\t\t6.print\n");
	printf("7.insert\t8.quit\n");
	printf("what function your want to use 1-8:\n");
	scanf ("%d",&m);
	while (m != 8)
	{
		if (  m>8 || m<1 )
		{	printf("please enter again:");
			scanf("%d" ,&m);
			continue;
		}
		if (1 == m){
			destroy(p);				//使用destory函数
			printf("what do you want to do:\n");
			printf("1.create new lian biao\t\t2.quit\n");
			printf("please enter your choice:");
			scanf("%d",&m);
			while(1){
				if(m==1){
						printf("please enter the num to create the shu zu(-1 to end ):");
						scanf("%d",&m);
						while(m != -1){
					if(number_1  ==  0){
						a=(int*)malloc(sizeof(int));
						}
					else{
						a=(int*)realloc((void*)a,(number_1+1)*sizeof(int));
						}
						a[number_1]=m;
						number_1++;
						scanf("%d",&m);
				}
						*head = p = create(a,number_1);
						number_1=0;
					break;
				}
				else if(m==2){
						printf("Tanks for using\n");
						return 0;
					}
				else{
					printf("the number your input is error\nplease enter again:");
					scanf("%d",&m);
				}
			}
		}
		if ( 2== m){							//使用delete函数
			
			while(p != NULL){
				printf("%d\t",p->data);
				p = p->next;
			}
			printf("\n");
			p=*head;
			int i=0;
			while(p != NULL){
				printf("%d\t",i++);
				p=p->next;
			}
			p=*head;
			printf("\n");
			printf("where the place you want to delete:");
			scanf("%d",&i);
			
			t=delete_(head,i,l);	
			p=*head;
			if(t==SUCCESS)
			printf("the num you delete is %d\n\n",*l);
		}
		if ( 3 == m ){									//使用search函数
			while(p != NULL){
				printf("%d\t",p->data);
				p = p->next;
			}
			printf("\n");
			p=*head;
			int i=0;
			while(p != NULL){
				printf("%d\t",i++);
				p=p->next;
			}
			p=*head;
			printf("\n");
			printf("waht data you wang to find:");
			scanf("%d",l);
			m = search(p,*l);
			printf("the position is %d\n",m);
		}
		if ( 4 == m ){							//使用edit函数
		
			while(p != NULL){
				printf("%d\t",p->data);
				p = p->next;
			}
			printf("\n");
			p=*head;
			int i=0;
			while(p != NULL){
				printf("%d\t",i++);
				p=p->next;
			}
			p=*head;
			printf("\n");
			printf("where the place you want to change:");
			scanf("%d",&i);
			printf("what number your want to put in:");
			scanf("%d",l);
			t=edit(p,i,l);
			printf("the num you change is %d\n\n",*l);
		}
		if (5 == m) {
			//使用sort函数
			t=sort(head);
		}
		if(6 == m) {					//使用print函数
			print(p);
			printf("what function your want to use 1-8:");
			scanf( "%d" , &m);
			continue;
		}
		if(7==m){
			while(p != NULL){
				printf("%d\t",p->data);
				p = p->next;
			}
			printf("\n");
			p=*head;
			int i=0;
			while(p != NULL){
				printf("%d\t",i++);
				p=p->next;
			}
			p=*head;
			printf("\n");
			ptr_Node k;
			k = (Node*)malloc(sizeof(Node));
			printf("create a point,enter the number:");	
			scanf("%d",&k->data);
			printf("where position your want to insert:");
			scanf("%d",&i);
			t = insert(head,k,i);
			p=*head;
			
		}
		if(t==SUCCESS)
		{
			while(p != NULL){
			printf("%d\t",p->data);
			p = p->next;}
		}
		printf("\n");
		printf("\n");
		p=*head;
		printf("what function your want to use 1-8:");
		scanf( "%d" , &m);
	}
	
	
	
	
	
	
	free(head);
	free(l);
	destroy(p);
	return 0;
}

