// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stack.h"
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
			printf("your need to create ADT[Y/N]:");			//选择是否创建平且初始化栈，Y是初始化，N是退出
			scanf("%c",&tmp);
			if(tmp=='Y'){
					e=(ElemType *)malloc(sizeof(ElemType));			//给e分配空间
					head=initStack();								//获得初始化的栈
					break;											//跳出循环
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
		if(3==m){							//退出系统
		printf("thanks for using\n");
		return 0;
	}	
	}
	printf("There are 7 functions\n");
	printf("1.push\t2.destroyStack\t3.clearStack\n4.lengthStack\t\t5.pop\t\t6.getTop\n");
	printf("7.initStack\t8.quit\n");
	printf("what function your want to use 1-8:\n");
	scanf ("%d",&m);										//选择不同的功能，注意有些功能一旦选择就会退出系统
		while(1){
			if (  m>8 || m<1 )
		{	printf("please enter again:");					//判断是否有该功能
			scanf("%d" ,&m);
			continue;
		}
		if(m==1){
			printf("please enter a char you want to push;");			//判断当输入的字符是空格的时候停止入栈
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
			printf("thank for using\n");						//销毁这个栈，平且结束系统
			return 0;
			
		}
		if(m==3){
			t=	clearStack(head);								//清空栈的内容，但是保留head的地址
			if(t==SUCCESS){
				printf("clear is SUCCESS\n");
			}
		}
		if(m==4){												//了解到栈的长度
			
			printf("the length is %d\n",head->count+1);
		}
		if(m==5){
				t=pop(head,e);								//取出栈顶，成功就继续运行这个系统
				if(t==SUCCESS){
					printf("your pop the char is %c\n",*e);
					printf("pop success\n");
				}
				else{														//当pop失败时候系统会告知失败并且结束系统
				printf("char you push is ERROR\n");
				return 0;
			}
		}
		if(m==6){
				p=getTop(head);
				if(p!=NULL){												//获得栈顶的地址，并且输出栈顶的字符
					printf("gettop is SUCCESS\n");
					printf("the top char is %c\n",p->data);
				}
		}
		if(m==7){
			
				destroyStack(head);												//重新初始化栈
																				//对旧的栈进行销毁，然后创建新的栈
				head=initStack();
				if(head!=NULL){
					printf("the old STack is destroy\n");
					printf("new is SUCCESS\n");
				
			}
				if(head==NULL) return 0;
			
		}
		if(m==8){
			break;								//跳出循环
		}
		
	
		printf("what function your want to use 1-8:\n");				//让你再次选择公共
		scanf ("%d",&m);
		}
		p=head->top;
		while(p){															//当退出之后，对栈内地内容，从栈顶开始进行输出
		printf("%c\t",p->data);					
		p=p->next;}
	destroyStack(head);					//销毁栈						
	free(e);						//释放e的空间
	printf("thanks for using\n");
	return 0;
}

