#include "stdafx.h"
#include "stack.h"
LinkStack* createL(void) {
	ElemType m;							//��������
	LinkStackPtr *p;					//����ָ�����
	p = (LinkStackPtr *)malloc(sizeof(LinkStackPtr));			//��ָ���������ռ�
	double tmp = 0;												//�Ը��������ĳ�ʼ��
	int i = 0,*j;
	j = (int*)malloc(sizeof(int));							//Ϊint��ָ�����ռ�
	
	double k = 0.1;								
	LinkStackPtr t;
	LinkStack *head, *head_1;								//����ջ
	head = initStack();										//��ջ���г�ʼ��
	head_1 = initStack();

	if (!head || !head_1 || !j || !p) return NULL;				//�ж��Ƿ��ж�ָ�������ռ�
	if (j) *j = 0;
	m = getchar();
	while(m==' '||m=='\n')										//ʡ������ʽ��֮ǰ�Ķ���
	m = getchar();
	
	while (m != ' ') {											//�ж��Ƿ�Ϊ�ո��ַ�
		if (m >= '0'&&m <= '9' || m == '.') {					//�ж��Ƿ�Ϊ�����ַ�������С�����ַ�
			if (m >= '0'&&m <= '9') {							//�ж��Ƿ�������
				
				while (m>='0' && m<='9') {					//���ַ�ת��Ϊ����
					i = (m - '0') + i * 10;
					*j = 1;
					m = getchar();
				}
			}
			 if (m == '.' || *j == 2) {						//�ж��Ƿ�ΪС�����ַ�
				m = getchar();
				while (m<'0' || m>'9') {					//��С�����������ַ�ת��Ϊ����
					tmp = (m - '0')*k + tmp;
					k *= 0.1;
					m = getchar();
					*j = 2;
					
				}

			}
			// printf("%d\n", i);
			tmp = i + tmp;								//���������
			t = (StackNode*)malloc(sizeof(StackNode));			//��t�����ڴ�
			t->data_1 = tmp;								//��t���и�ֵ
			t->data = 0;
			push(head, t);										//��t��ջ
			tmp = 0;													//tmp��i�ĳ�ʼ��
			i = 0;
		}
		
 		 if (m == '*' || m == '/' || m == '+' || m == '-' || m == ')' || m == '(') {						//�����������ʱ��
			
			 if (*j == 0) return NULL;
			if ((m == '*' || m == '/' || m == '+' || m == '-')&&(head_1->top) && (head_1->top->data == '-' || head_1->top->data == '+' || head_1->top->data == '*' || head_1->top->data == '/' || head_1->top->data == '(' )&&(*j==3)) {
				destroyStack(head);																			//��ͬʱ���������������ʱ�򱨴�
				destroyStack(head_1);																		
				free(p);
				free(j);
				return NULL;
			}
			if (isEmpty(head_1) == SUCCESS || m == '(' || head_1->top->data == '(') {							//�ж�ջ�Ƿ�Ϊ��
				t = (StackNode *)malloc(sizeof(StackNode));														//��t��ջ
				t->data_1 = -1.09;
				t->data = m;
				push(head_1, t);

			}
			else {				//���ǿ�ջ��������ʱ�����������У��ж����ȼ������ҽ����ȼ��ߵ�����ջ
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
			printf("%c", m);																		//�жϲ��Ǽ�������ŵ�ʱ��ᱨ����ʾ����ķ���
			getchar();																				//��������
			destroyStack(head);
			destroyStack(head_1);
			free(p);
			free(j);
			return NULL;
		}
		
		if (m == ' ' ) break;
		m = getchar();
	}
	while (head_1->top != NULL) {										//��������һ��ջ��ȫ�������������ջ��

		pop(head_1, p);
		push(head, *p);
	}
	t = head->top;
	while (t){														//��ʾջ���ڵ�����
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
}			//�ɼ����ݣ����ҽ�������ջ
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
