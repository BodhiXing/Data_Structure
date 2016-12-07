#include <stdio.h>
#include <malloc.h>
#include "DLinkList.h"

typedef struct _tag_DLinkList
{
	DLinkListNode header;
	DLinkListNode* slider; //指向第一个元素 
	int length;
}TDLinkList;

/*create DLinkList*/
DLinkList* DLinkList_Create()
{
	TDLinkList* ret = (TDLinkList*)malloc(sizeof(TDLinkList));
	
	if(ret != NULL)
	{
		ret->length = 0;
		ret->header.next = NULL;
		ret->header.pre = NULL;
		ret->slider = NULL;
	}
	
	return ret;
}  

void DLinkList_Destroy(DLinkList* list)
{
	free(list);
}

void DLinkList_Clear(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList*)list;
	
	if(sList != NULL)
	{
		sList->length = 0;
		sList->header.next = NULL;
		sList->header.pre = NULL;
		sList->slider =  NULL;
	}
}

int Get_DLinkList_Length(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList*)list;
	int ret = -1;
	
	if(sList != NULL)
	{
		ret = sList->length;
	}
	
	return ret;
}

int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos)
{
	TDLinkList* sList = (TDLinkList*)list;
	int ret = (sList!=NULL)&&(pos>=0)&&(node!=NULL);
	int i;
	if(ret)
	{
		DLinkListNode* current = (DLinkListNode*)sList;  //head node
		DLinkListNode* next = NULL;
		for(i=0;(i<pos)&&(current->next != NULL);i++)
		{
			current = current->next;
		}
		next = current->next;
		
		current->next = node;
		node->next = next;
		
		if(next != NULL)//第一个节点 
		{
			next->pre = node;
			
		}
		node->pre = current;
		
		if(sList->length == 0) //第一个元素 
		{
			node->pre = NULL; 
			sList->slider = node; 
		}
		sList->length++;
	}
	return ret;
}

DLinkListNode* DLinkList_Get_Elem(DLinkList* list, int pos)
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int i = 0;
	
	if((sList!=NULL) && (pos>=0) && (pos<sList->length))
	{
		DLinkListNode* current = (DLinkListNode*)sList;
		
		for(i=0;i<pos;i++)
		{
			current = current->next;
		}
		ret = current->next;
	}
	
	return ret;
}

DLinkListNode* DLinkList_Delete_Elem(DLinkList* list, int pos)
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int i;
	
	if((sList!=NULL) && (0<=pos) && (pos<sList->length))	
	{
		DLinkListNode* current = (DLinkListNode*)sList;
		DLinkListNode* next = NULL;
		for(i=0;i<pos;i++)
		{
			current = current->next;
		}
		ret = current->next;
		next = ret->next;
		current->next = ret->next;
		
		if( next != NULL )      //为最后一个元素 
        {
            next->pre = current;
            
            if( current == (DLinkListNode*)sList )  //为表头 
            {
                next->pre = NULL;
            }
        }
        
        if(sList->slider == ret)
        {
        	sList->slider = next;
		}
		sList->length--;
	}
	return ret;
}

DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node)
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int i;
	
	if(sList != NULL)
	{
		DLinkListNode* current = (DLinkListNode*)sList;
		for(i=0; i<sList->length; i++)
		{
			if( current->next == node )
            {
                ret = current->next;
                break;
            }
            current = current->next; 
		} 
		
		if( ret != NULL )
        {
            DLinkList_Delete_Elem(sList, i);
        }
	} 
} 


DLinkListNode* DLinkList_Reset(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	
	if(sList != NULL)
	{
		sList->slider = sList->header.next;
		ret = sList->slider;
	}
	
	return ret;
}

DLinkListNode* DLinkList_Current(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	
	if(sList != NULL)
	{
		ret = sList->slider;
	}
	
	return ret;
}

DLinkListNode* DLinkList_Next(DLinkList* list)
{
    TDLinkList* sList = (TDLinkList*)list;
    DLinkListNode* ret = NULL;
    
    if( (sList != NULL) && (sList->slider != NULL) )
    {
        ret = sList->slider;
        sList->slider = ret->next;
    }
    
    return ret;
}

DLinkListNode* DLinkList_Pre(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	
	if( (sList != NULL) && (sList->slider != NULL) )
    {
        ret = sList->slider;
        sList->slider = ret->pre;
    }
    
	return ret;
}
