#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include "integerCompare.h"
#include "Compare.h"
#include "Data.h"

typedef struct LinkedList LinkedList;
typedef struct Item Item;

struct Item{
  Item *next;
  Data *data;
};
struct LinkedList{
  Item *head;
  Item *tail;
  int len;
};
void listInit ( LinkedList *list);
void listAdd(LinkedList *list, Item*item);
void createItem(Item *item,void * data,Item *next);
Item *listSearch(LinkedList *list, uint32_t key, Compare integerKeyCompare);
void *listRemove(LinkedList *list,uint32_t key, Compare integerCompare);
void listReplace(LinkedList *list,Item *item,uint32_t key, Compare integerCompare);
#endif // _LINKEDLIST_H
