/********************************************************************************************************************
Name.......................................:tatus delete_T(ptr_TNode *head, int index, int *data)
Description................................:定义一个结构体，以生成链表
Parameters.................................:
*********************************************************************************************************************/
typedef struct TNode {				//声明及定义结构体
	int data;    
	struct TNode *next;    
	struct TNode *pre; 
}TNode, *ptr_TNode; 
/********************************************************************************************************************
Name.......................................:tatus delete_T(ptr_TNode *head, int index, int *data)
Description................................:定义一个结构体，构成返回函数的值
Parameters.................................:
*********************************************************************************************************************/
typedef enum Status {  
	SUCCESS, ERROR 
}Status; 
 typedef struct Node {    
	 int data;    
	 struct Node *next; 
 }Node, *ptr_Node; 
 #include <stdio.h>
#include <stdlib.h>