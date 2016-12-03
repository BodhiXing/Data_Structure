#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"

typedef unsigned int TSeqListNode;
typedef struct _tag_SeqList
{
	int capacity;
	int length;
	TSeqListNode* node;	
}TSeqList;

/* Create list */
void* SeqList_Create(int capacity)
{
	TSeqList* ret = NULL;
	if(capacity >= 0)
	{
		ret = (TSeqList*)malloc(sizeof(TSeqList)+sizeof(TSeqListNode)*capacity);	
	}
	if(NULL != ret)
	{
		ret->length = 0;
		ret->capacity = capacity;
		ret->node = (TSeqListNode*)(ret+1);
	}
	return ret;
}

/*Destroy list*/
void SeqList_Destroy(SeqList* list)
{
	free(list);
}

void SeqList_Clear(SeqList* list)
{
	TSeqList* sList = (TSeqList*)list;
	if(NULL != sList)
	{
		sList->length = 0;
	}
}

/*get length*/
int  Get_SeqList_Length(SeqList* list)
{
	int ret = -1;
	TSeqList* sList = (TSeqList*)list;
	if(NULL != sList)
	{
		ret = sList->length;
	}
	
	return ret;
}

/*get capacity*/
int Get_SeqList_Capacity(SeqList* list)
{
	int ret = -1;
	TSeqList* sList = (TSeqList*)list;
	if(NULL != sList)
	{
		ret = sList->capacity;
	}
	
	return ret;
}

/*insert element*/
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	TSeqList* sList = (TSeqList*)list;
    int ret = (sList != NULL);
    int i = 0;
    
    ret = ret && (sList->length + 1 <= sList->capacity);
    ret = ret && (0 <= pos);
    
    if( ret )
    {
        if( pos >= sList->length )
        {
            pos = sList->length;
        }
        
        for(i=sList->length; i>pos; i--)
        {
            sList->node[i] = sList->node[i-1];
        }
        
        sList->node[i] = (TSeqListNode)node;
        
        sList->length++;
    }
    
    return ret;
}

/*get elelment*/
SeqListNode* SeqList_Get_Elem(SeqList* list, int pos)
{
	TSeqList* sList = (TSeqList*)list;
	SeqListNode* ret = NULL;
	
	if((sList != NULL) && (pos>=0) && (pos < sList->length))
	{
		ret = (TSeqListNode*)sList->node[pos];
	}
	
	return ret;
}

/*delete element*/
SeqListNode* SeqList_Delete_Elem(SeqList* list, int pos)
{
	TSeqList* sList = (TSeqList*)list;
	SeqListNode* ret = SeqList_Get_Elem(list,pos);
	int i = 0;
	
	if(NULL != ret)
	{
		for(i=pos+1;i<sList->length;i++)
		{
			sList->node[i-1] = sList->node[i];
		 } 
		sList->length--;
	} 
	return ret;
}
