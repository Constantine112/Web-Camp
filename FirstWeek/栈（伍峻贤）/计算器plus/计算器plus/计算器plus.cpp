// ������plus.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stack.h"

int main()
{
	int i;
	printf("\n");
	printf("		     ====================================  \n");
	printf("		    ||       ���� 1 ����������        || \n");
	printf("		    ||                                || \n");
	printf("                    ||       ���� 2 �˳�ϵͳ           || \n");
	printf("		     ====================================  \n\n\n");
	printf("\n--------------------------------------------------------------------------------\n");
	printf("                                        \n");
	printf("      ~~^^~~                              \n");
	printf("     ^~^~~^~^                          \n");
	printf("     [o    o]                        \n");
	printf("     (	[]  )      --------------��������-------------                      \n");
	printf("      { __ }                            \n");
	printf("       <~~>                             \n");
	printf("                                                                 @author:Con\n\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("please enter your choice:");
	scanf_s("%d", &i);
	LinkStack* t;
	if (i == 1) {
		while (i == 1) {
			printf("please enter nunber you want to calculate�ո��������:\n");
			t = createL();
			if (t == NULL) {
				printf("There some Errors");
				getchar();
				
				return 0;
			}
			calculate(t);
			printf("do you want again?\n");
			printf("please enter 1.again   2.quit:");
			scanf_s("%d", &i);
		}
	}
	printf("thank for using\n");
	getchar();
	
    return 0;
}

