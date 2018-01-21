#include <stdio.h>
#include "linkedlist.h"
#include "Compare.h"
#include "integerCompare.h"


void listInit ( LinkedList *list)
{
  list->head = NULL;
  list->tail = NULL;
  list->len = 0;
}

void listAdd(LinkedList *list, Item*item)
{
  if(list->len == 0)
  {
  list->head =item;
  list->tail =item;
  }
  else
  {
    list->tail->next=item;
    list->tail = item;
  }
  list->len += 1 ;
  item->next = NULL;
}

void listReplace(LinkedList *list,Item *item,uint32_t key, Compare integerCompare){
  int X =0;
    Item *now = list->head;
    while(now != NULL){
    if(integerCompare((void *)key,(void *)&(((Data *)(now->data))->key))==1){
      ((Data *)(now->data))->name =((Data *)(item->data))->name;
      X=1;
    }
      now = now->next;
    }

  if(list->len==0){
    list->head = item;
    list->tail = item;
    list->len  = 1;
    item->next = NULL;
  }
  else{
    if(X==0){
    list->tail->next=item;
    list->tail = item;
    list->len += 1;
    item->next = NULL;
  }
  }

}

void createItem(Item *item,void * data,Item *next){
  item->data=data;
  item->next=next;
}

void *listRemove(LinkedList *list,uint32_t key, Compare integerCompare){
  Item *before = NULL;
  Item *now = list->head;

	if(list->head==NULL)
		return NULL;

	else{
		while(integerCompare((void *)key,now->data)!=NULL){
			before = now;
			now = now->next;
			}

			if(now==list->head){
				if(list->head==list->tail){
					listInit(list);
				}
				else{
					now = now->next;
					list->head = now;
					list->len-= 1;
					}
			}

			else if(now == list->tail){
				list->tail=before;
				before->next=NULL;
				list->len-= 1;
				}

			else{
				before->next=now->next;
				list->len-= 1;
				}
			return now->data;
		}
}

Item *listSearch(LinkedList *list, uint32_t key, Compare integerCompare){
    Item *before = NULL;
    Item *now = list->head;
    if(now == NULL)
      return NULL;
    else
      while(integerCompare((void*)key,(void*)&(((Data *)now->data))->key) !=1)
      {
        before = now;
        now = now->next;
        break;
      }
      return now->data;
}
