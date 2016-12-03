#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	SeqList* list = SeqList_Create(5);
	int ch[5]={0,1,2,3,4};
	int index = 0;
	int *p = NULL;
	
	
	for(index=0;index<sizeof(ch)/(sizeof(ch[0]));index++)
	{
		SeqList_Insert(list,&ch[index],0);
	}
	
	
	for(index=0;index<Get_SeqList_Length(list);index++)
	{
		p = (int*)SeqList_Get_Elem(list,index);
		printf("%d\n",*p);
	}
	printf("**************\n");

	while(Get_SeqList_Length(list) > 0)
	{
		p = (int*)SeqList_Delete_Elem(list,0);
		printf("%d\n",*p);
	} 
	
	SeqList_Destroy(list);
	return 0;
}
