/********************************************************************************************************************
Name.......................................:tatus delete_T(ptr_TNode *head, int index, int *data)
Description................................:����һ���ṹ�壬����������
Parameters.................................:
*********************************************************************************************************************/
typedef struct TNode {				//����������ṹ��
	int data;    
	struct TNode *next;    
	struct TNode *pre; 
}TNode, *ptr_TNode; 
/********************************************************************************************************************
Name.......................................:tatus delete_T(ptr_TNode *head, int index, int *data)
Description................................:����һ���ṹ�壬���ɷ��غ�����ֵ
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