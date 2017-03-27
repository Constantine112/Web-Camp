#include "stdafx.h"
#include "stack.h"
LinkStack* createL(void) {
	ElemType m;							//创建变量
	LinkStackPtr *p;					//创建指针变量
	p = (LinkStackPtr *)malloc(sizeof(LinkStackPtr));			//给指针变量分配空间
	double tmp = 0;												//对各个变量的初始化
	int i = 0,*j;
	j = (int*)malloc(sizeof(int));							//为int型指针分配空间
	
	double k = 0.1;								
	LinkStackPtr t;
	LinkStack *head, *head_1;								//创建栈
	head = initStack();										//对栈进行初始化
	head_1 = initStack();

	if (!head || !head_1 || !j || !p) return NULL;				//判断是否有对指针分配带空间
	if (j) *j = 0;
	m = getchar();
	while(m==' '||m=='\n')										//省略运算式子之前的东西
	m = getchar();
	
	while (m != ' ') {											//判断是否为空格字符
		if (m >= '0'&&m <= '9' || m == '.') {					//判断是否为数字字符或者是小数点字符
			if (m >= '0'&&m <= '9') {							//判断是否是数字
				
				while (m>='0' && m<='9') {					//将字符转换为数字
					i = (m - '0') + i * 10;
					*j = 1;
					m = getchar();
				}
			}
			 if (m == '.' || *j == 2) {						//判断是否为小数点字符
				m = getchar();
				while (m<'0' || m>'9') {					//将小数点后的数字字符转换为数字
					tmp = (m - '0')*k + tmp;
					k *= 0.1;
					m = getchar();
					*j = 2;
					
				}

			}
			// printf("%d\n", i);
			tmp = i + tmp;								//将数字相加
			t = (StackNode*)malloc(sizeof(StackNode));			//给t分配内存
			t->data_1 = tmp;								//对t进行赋值
			t->data = 0;
			push(head, t);										//讲t入栈
			tmp = 0;													//tmp和i的初始化
			i = 0;
		}
		
 		 if (m == '*' || m == '/' || m == '+' || m == '-' || m == ')' || m == '(') {						//当是运算符的时候
			
			 if (*j == 0) return NULL;
			if ((m == '*' || m == '/' || m == '+' || m == '-')&&(head_1->top) && (head_1->top->data == '-' || head_1->top->data == '+' || head_1->top->data == '*' || head_1->top->data == '/' || head_1->top->data == '(' )&&(*j==3)) {
				destroyStack(head);																			//当同时出现两个运算符的时候报错
				destroyStack(head_1);																		
				free(p);
				free(j);
				return NULL;
			}
			if (isEmpty(head_1) == SUCCESS || m == '(' || head_1->top->data == '(') {							//判断栈是否为空
				t = (StackNode *)malloc(sizeof(StackNode));														//讲t入栈
				t->data_1 = -1.09;
				t->data = m;
				push(head_1, t);

			}
			else {				//不是空栈或右括号时候在这里运行，判断优先级，并且将优先级高的先入栈
				if ((m == '*' || m == '/') && (head_1->top->data == '+' || head_1->top->data == '-')) {
					t = (StackNode *)malloc(sizeof(StackNode));						
					t->data_1 = -1.09;
					t->data = m;
					push(head_1, t);


				}		//

				else if ((m == '*' || m == '/') && (head_1->top->data == '*' || head_1->top->data == '/')) {
					t = (StackNode *)malloc(sizeof(StackNode));
					t->data_1 = -1.09;
					t->data = m;

					pop(head_1, p);
					push(head, *p);
					push(head_1, t);
				}
				else if ((m == '+' || m == '-') && (head_1->top->data == '+' || head_1->top->data == '-'))
				{
					t = (StackNode *)malloc(sizeof(StackNode));
					t->data_1 = -1.09;
					t->data = m;
					pop(head_1, p);
					push(head, *p);
					push(head_1, t);
				}
				else if (m == ')') {
					pop(head_1, p);

					while ((*p)->data != '(') {

						push(head, *p);
						pop(head_1, p);
					}
				}
			}
			*j = 3;
		}

		if((m != '*' && m != '/' && m != '+' && m != '-' && m != ')' && m != '('&&  m != '.'&&m!=' ' && m != '\n')&& (m < '0'||m > '9')) {
			printf("%c", m);																		//判断不是简单运算符号的时候会报错并显示错误的符号
			getchar();																				//销毁链表
			destroyStack(head);
			destroyStack(head_1);
			free(p);
			free(j);
			return NULL;
		}
		
		if (m == ' ' ) break;
		m = getchar();
	}
	while (head_1->top != NULL) {										//将存在另一个栈顶全部运算符都放入栈内

		pop(head_1, p);
		push(head, *p);
	}
	t = head->top;
	while (t){														//显示栈现在的内容
		if (t->data) {
			printf("%c\t", t->data);
		}
		else {
			printf("%lf\t", t->data_1);
		}
		t = t->next;
	}
	
	
	free(p);
	free(j);
	destroyStack(head_1);
	return head;
}			//采集数据，并且将数据入栈
Status calculate(LinkStack* head_1){
	if (!head_1) return ERROR;
	LinkStack* head;
	head = initStack();
	LinkStackPtr *p,*t1,*t2;
	p = (LinkStackPtr *)malloc(sizeof(LinkStackPtr));
	t1 = (LinkStackPtr *)malloc(sizeof(LinkStackPtr));
	t2 = (LinkStackPtr *)malloc(sizeof(LinkStackPtr));
	if (!p || !head || !t1 || !t2)
		return ERROR;

	while (head_1->top) {
		pop(head_1, p);
		push(head, *p);
	}
	while (head->top != NULL) {
		if (!head->top->data) {
			pop(head, p);
			push(head_1, *p);
		}
		else{
			pop(head_1, t1);
			pop(head_1, t2);
			pop(head, p);
			if (!t1 || !t2) {
				printf("there some ERROR");
				return ERROR;
			}
			switch ((*p)->data) {
			case '+':(*t1)->data_1 = (*t1)->data_1 + (*t2)->data_1;
					break;
			case '-':(*t1)->data_1 = (*t2)->data_1 - (*t1)->data_1;
					break;
			case '*':(*t1)->data_1 = (*t1)->data_1 * (*t2)->data_1;
					break;
			case '/':(*t1)->data_1 = (*t2)->data_1 / (*t1)->data_1;
					break;
			}
			push(head_1, *t1);
		}
	}
	printf("\n");
	printf("The sum is %lf", head_1->top->data_1);
	
	destroyStack(head);
	destroyStack(head_1);
	free(t1);
	free(t2);
	free(p);
	return SUCCESS;
}
