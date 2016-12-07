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
˫��������²����� 
1.	��ȡ��ǰ�α�ָ�������Ԫ��
2.	���α�����ָ�������еĵ�һ������Ԫ��
3.	���α��ƶ�ָ�������е���һ������Ԫ��
4.	���α��ƶ�ָ�������е���һ������Ԫ��
5.	ֱ��ָ��ɾ�������е�ĳ������Ԫ��
*********************************************/
DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node);
DLinkListNode* DLinkList_Reset(DLinkList* list);
DLinkListNode* DLinkList_Current(DLinkList* list);
DLinkListNode* DLinkList_Next(DLinkList* list);
DLinkListNode* DLinkList_Pre(DLinkList* list);
#endif


