#ifndef _DLinkList_H_
#define _DLinkList_H_

typedef void DLinkList;
typedef struct _tag_DLinkListNode DLinkListNode;
struct _tag_DLinkListNode
{
	DLinkListNode* next;
	DLinkListNode* pre;
};

DLinkList* DLinkList_Create();

void DLinkList_Destroy(DLinkList* list);

void DLinkList_Clear(DLinkList* list);

int Get_DLinkList_Length(DLinkList* list);

int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos);

DLinkListNode* DLinkList_Get_Elem(DLinkList* list, int pos);

DLinkListNode* DLinkList_Delete_Elem(DLinkList* list, int pos);

/******************************************** 
双向链表的新操作： 
1.	获取当前游标指向的数据元素
2.	将游标重置指向链表中的第一个数据元素
3.	将游标移动指向到链表中的下一个数据元素
4.	将游标移动指向到链表中的上一个数据元素
5.	直接指定删除链表中的某个数据元素
*********************************************/
DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node);
DLinkListNode* DLinkList_Reset(DLinkList* list);
DLinkListNode* DLinkList_Current(DLinkList* list);
DLinkListNode* DLinkList_Next(DLinkList* list);
DLinkListNode* DLinkList_Pre(DLinkList* list);
#endif


