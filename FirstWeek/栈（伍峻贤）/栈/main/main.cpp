// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stack.h"
int main(int argc, char* argv[])
{	printf("\n");
	printf("		     ====================================  \n");
	printf("		    ||       ���� 1 ����lianbiao        || \n");
	printf("		    ||       ���� 2 ��ʹ��˵��          || \n");
	printf("                    ||       ���� 3 �˳�ϵͳ            || \n");  
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
	char tmp;
	int m;
	LinkStack *head;
	LinkStackPtr p;
	ElemType *e;
	Status t;
	printf("please enter your choice:");				
	scanf("%d",&m);	
	while(m>0&&m<4){
		if(m==1){
			printf("your need to create ADT[Y/N]:");			//ѡ���Ƿ񴴽�ƽ�ҳ�ʼ��ջ��Y�ǳ�ʼ����N���˳�
			scanf("%c",&tmp);
			if(tmp=='Y'){
					e=(ElemType *)malloc(sizeof(ElemType));			//��e����ռ�
					head=initStack();								//��ó�ʼ����ջ
					break;											//����ѭ��
			}	
			if(tmp=='N'){
			printf("thank for using\n");
			return 0;
		}
		}
			if(2==m){
		printf("There are 6 functions\n");
		printf("1.push:push a char to the stack\t");
		printf("2.destroyStack:destory the stack\n");
		printf("3.clearStack:clearStack the stack\t ");
		printf("4.lengthStack:know the length of the stack\n");
		printf("5.pop:get achar form the stack\t\t");
		printf("6.getTop:get  the top of stack\n");
		printf("7.initStack:init the stack\n");
		printf("please enter your choice:");
		scanf("%d",&m);

	}
		if(3==m){							//�˳�ϵͳ
		printf("thanks for using\n");
		return 0;
	}	
	}
	printf("There are 7 functions\n");
	printf("1.push\t2.destroyStack\t3.clearStack\n4.lengthStack\t\t5.pop\t\t6.getTop\n");
	printf("7.initStack\t8.quit\n");
	printf("what function your want to use 1-8:\n");
	scanf ("%d",&m);										//ѡ��ͬ�Ĺ��ܣ�ע����Щ����һ��ѡ��ͻ��˳�ϵͳ
		while(1){
			if (  m>8 || m<1 )
		{	printf("please enter again:");					//�ж��Ƿ��иù���
			scanf("%d" ,&m);
			continue;
		}
		if(m==1){
			printf("please enter a char you want to push;");			//�жϵ�������ַ��ǿո��ʱ��ֹͣ��ջ
			tmp=getchar();												
		while(tmp!=' ')
		{	 if(tmp=='!'){
			t=	BackSpace(head);
			
			if(t==ERROR){
				destroyStack(head);
				return 0;
			}
			tmp=getchar();
			
			}
			else{
			t=push(head,tmp);

			if( t == ERROR ){
			destroyStack(head);
			return 0;
			}
				
			tmp=getchar();	
			}
		}
					
		}
		if(m==2){
			destroyStack(head);
			printf("thank for using\n");						//�������ջ��ƽ�ҽ���ϵͳ
			return 0;
			
		}
		if(m==3){
			t=	clearStack(head);								//���ջ�����ݣ����Ǳ���head�ĵ�ַ
			if(t==SUCCESS){
				printf("clear is SUCCESS\n");
			}
		}
		if(m==4){												//�˽⵽ջ�ĳ���
			
			printf("the length is %d\n",head->count+1);
		}
		if(m==5){
				t=pop(head,e);								//ȡ��ջ�����ɹ��ͼ����������ϵͳ
				if(t==SUCCESS){
					printf("your pop the char is %c\n",*e);
					printf("pop success\n");
				}
				else{														//��popʧ��ʱ��ϵͳ���֪ʧ�ܲ��ҽ���ϵͳ
				printf("char you push is ERROR\n");
				return 0;
			}
		}
		if(m==6){
				p=getTop(head);
				if(p!=NULL){												//���ջ���ĵ�ַ���������ջ�����ַ�
					printf("gettop is SUCCESS\n");
					printf("the top char is %c\n",p->data);
				}
		}
		if(m==7){
			
				destroyStack(head);												//���³�ʼ��ջ
																				//�Ծɵ�ջ�������٣�Ȼ�󴴽��µ�ջ
				head=initStack();
				if(head!=NULL){
					printf("the old STack is destroy\n");
					printf("new is SUCCESS\n");
				
			}
				if(head==NULL) return 0;
			
		}
		if(m==8){
			break;								//����ѭ��
		}
		
	
		printf("what function your want to use 1-8:\n");				//�����ٴ�ѡ�񹫹�
		scanf ("%d",&m);
		}
		p=head->top;
		while(p){															//���˳�֮�󣬶�ջ�ڵ����ݣ���ջ����ʼ�������
		printf("%c\t",p->data);					
		p=p->next;}
	destroyStack(head);					//����ջ						
	free(e);						//�ͷ�e�Ŀռ�
	printf("thanks for using\n");
	return 0;
}

