#ifndef _SEQLIST_H_
#define _SEQLIST_H_

typedef void SeqList;
typedef void SeqListNode;

void* SeqList_Create(int capacity);

void SeqList_Destroy(SeqList* list);

void SeqList_Clear(SeqList* list);

int Get_SeqList_Length(SeqList* list);

int Get_SeqList_Capacity(SeqList* list);

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos);

SeqListNode* SeqList_Get_Elem(SeqList* list, int pos);

SeqListNode* SeqList_Delete_Elem(SeqList* list, int pos);

#endif

