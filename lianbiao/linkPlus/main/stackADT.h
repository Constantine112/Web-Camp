#include<stdio.h> 
#include <stdlib.h>
#include "stdafx.h"
//声明结构体
typedef struct Node {    
	int data;   
	struct Node *next; 
}Node, *ptr_Node; 
 
typedef enum Status {  
	SUCCESS, ERROR 
}Status; 

//声明各种函数
 /**********************************************************************************
 Name............: ptr_Node create(int *arr, int n)
 Description.....: 创建链表
 Parameters......: arr是数组指针，n代表数组大小
 Return values...: 成功 return头节点 失败-return NULL
**********************************************************************************/
ptr_Node create(int *arr, int n);				//用数组创建链表
 /**********************************************************************************
 Name............: void destroy(ptr_Node head)
 Description.....: 销毁链表 
 Parameters......: head-指向有节点，在第 index 位后面插入 node 结点 
 Return values...: 插入成功返回 SUCCESS，失败返回 ERROR 
**********************************************************************************/
void destroy(ptr_Node head);					//摧毁链表
/**********************************************************************************
 Name............: Status insert(ptr_Node *head, ptr_Node node, int index)
 Description.....: 插入链表 
 Parameters......: head-指向头节点  在第 index 位后面插入 node 结点 
 Return values...: 成功-return TRUE 失败-return FALSE
**********************************************************************************/

 Status insert(ptr_Node *head, ptr_Node node, int index);		//在第 index 位后面插入 node 结点 
																//插入成功返回 SUCCESS，失败返回 ERROR 
 /**********************************************************************************
 Name............: Status delete_(ptr_Node *head, int index, int *data);	
 Description.....: 删除链表
 Parameters......: head-指向头节点  删除第 index 位后面的结点 ，并且把删除的结点的值保存到（*data）中 
 Return values...: 成功-return TRUE 失败-return FALSE
**********************************************************************************/
 Status delete_(ptr_Node *head, int index, int *data);			//删除第 index 位节点后面的节点，将删除的结点的值保存到（*data）中 
																//删除成功返回 SUCCESS，其他情况返回 ERROR Status 
 /**********************************************************************************
 Name............: int search(ptr_Node head, int data);	
 Description.....: 搜索链表 
 Parameters......: head-指向头节点 链表中查找节点值与 data 相等的节点
 Return values...: 成功-return 位置 失败-return -1
**********************************************************************************/
 int search(ptr_Node head, int data);							//在链表中查找节点值与 data 相等的节点，并返回找到的第一个节点的前一个节点的位置 
																//（例：头节点相等，返回 0），没找到或者其他情况返回-1
 /**********************************************************************************
 Name............: Status edit(ptr_Node head, int index, int *data);	
 Description.....: 修改链表 
 Parameters......: head-指向头节点 index-位置 data保存原值
 Return values...: 成功-return TRUE 失败-return FALSE
**********************************************************************************/
 Status edit(ptr_Node head, int index, int *data);				//将链表中 index 位点后面的结点的值修改为(*data)，将原值保存到(*data) 
																//修改成功返回 SUCCESS，其他情况返回 ERROR 
 /**********************************************************************************
 Name............: void print(ptr_Node head);
 Description.....: 输出链表 
 Parameters......: head-指向头节点
 Return values...: 无
**********************************************************************************/
 void print(ptr_Node head);										//将链表结点值按照一定的格式输出
 /**********************************************************************************
 Name............: Status sort(ptr_Node *head)
 Description.....: 排序链表
 Parameters......: head-指向头节点
 Return values...: 成功-return TRUE 失败-return FALSE
**********************************************************************************/
 Status sort(ptr_Node *head);									//实现单链表按照节点值大小升序