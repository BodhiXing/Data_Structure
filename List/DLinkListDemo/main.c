#include <stdio.h>
#include <stdlib.h>
#include "DLinkList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct  Value
{
	DLinkListNode header;
	int v;	
};

int main(int argc, char *argv[]) {
	int i = 0;
    DLinkList* list = DLinkList_Create();
    struct Value* pv = NULL;
    struct Value v1;
    struct Value v2;
    struct Value v3;
    struct Value v4;
    struct Value v5;
    
    v1.v = 1;
    v2.v = 2;
    v3.v = 3;
    v4.v = 4;
    v5.v = 5;
    
    DLinkList_Insert(list, (DLinkListNode*)&v1, Get_DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode*)&v2, Get_DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode*)&v3, Get_DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode*)&v4, Get_DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode*)&v5, Get_DLinkList_Length(list));
    
    for(i=0; i<Get_DLinkList_Length(list); i++)
    {
        pv = (struct Value*)DLinkList_Get_Elem(list, i);
        
        printf("%d\n", pv->v);
    }
    
    printf("\n");
    
    DLinkList_Delete_Elem(list, Get_DLinkList_Length(list)-1);
    DLinkList_Delete_Elem(list, 0);
    
	for(i=0; i<Get_DLinkList_Length(list); i++)
    {
        pv = (struct Value*)DLinkList_Get_Elem(list, i);
        
        printf("%d\n", pv->v);
    }
 	
	 //²âÊÔÐÂ·½·¨ 
 	printf("\n");
  	for(i=0; i<Get_DLinkList_Length(list); i++)
    {
        pv = (struct Value*)DLinkList_Next(list);
        
    	printf("%d\n", pv->v);
    }
    
	printf("\n");
    
    DLinkList_Reset(list);
    DLinkList_Next(list);
    
    pv = (struct Value*)DLinkList_Current(list);
    
    printf("%d\n", pv->v);
    
    DLinkList_DeleteNode(list, (DLinkListNode*)pv);
    
    pv = (struct Value*)DLinkList_Current(list);
    
    printf("%d\n", pv->v);
    
    DLinkList_Pre(list);
    
    pv = (struct Value*)DLinkList_Current(list);
    
    printf("%d\n", pv->v);
    
    printf("Length: %d\n", Get_DLinkList_Length(list));
  	
    DLinkList_Destroy(list);
	return 0;
}
