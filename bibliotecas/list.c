#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
 * Node constructor
 */
node* new_node(int info)
{
   node* node = (node*)malloc(sizeof(node));
   if(!node)
   {
      printf("\nWrong memory!\n");
      return NULL;
   }
      
   node->next = NULL;
   node->info = info;
   
   return node;
}

/*
 * List constructor
 */
list* new_list()
{
   list* list = (*list)calloc(sizeof(list));
   if(!list)
      printf("\nWrong memory!\n");

   return list;
}

/*
 * Return the reference node in k position
 */
node* get_node_k(unsigned int k, list* list)
{
   node* r;
   if(!list || k >= list->qtd)
      return NULL;
   
   r = list->last;
   unsigned int i = list->qtd;
   while((i--) > k)
      if(!r)
         return NULL;
      else
         r = r->next;
   
   return !r ? NULL : r->info;
}

/*
 * Set default value of indice
 */
void has_next_reboot(list* list)
{
   list->indice = list->first;
}

/*
 * Return the value of next element if there
 */
int has_next(list* list)
{
   int r;
   if(!list)
      return NULL;
   if(!list->indice)
      if(!list->first)
         return NULL;
      else
      {
         has_next_reboot(list);
         return NULL;
      }
   r = list->indice->info;
   list->indice = list->indice->next;
   return r;
}

/*
 * Add element in the list
 */
void add(int info, list* list)
{
   node* node;
   if(!list || !info)
      return;
   if(!(node = new_node(info)))
      return;
      
   if(!list->qtd)
      list->first = list->last = node;
      
   node->next = list->last;
   list->last = node;
   
   list->qtd++;
   
   has_next_reboot(list);
}

/*
 * Return the value of node in k position
 */
int get_k(unsigned int k, list* list)
{
   node* r = get_node_k(k, list);
   return !r ? NULL : r->info;
}

/*
 * Delete the element in k position
 */
void del_k(unsigned int k, list* list)
{
   node* after;
   node* k_node;
   
   after = list && list->qtd <= 1 ? get_node_k(k, list) : get_node_k(k+1, list);
   k_node = after ? after-> next : NULL;
   if(!k_node)
      return;
      
   after->next = k_node->next;
   list->first = k == 0 ? after : list->first;
   list->qtd--;
   free(k_node);
}

/*
 * Delete the list's element by info
 */
void del_n(int n, list* list)
{
   node* after = list ? list->last : return;
   node* n_node;
   
   while(after)
   {
      if(n_node->info == n)
      {
         n_node = after;
         after->next = n_node->next;
         free(node_n);
         list->qtd--;
         return;
      }
      after = after->next;
   }
}

/*
 * Return a list's copy
 */
list* copy(list* list)
{
   list* new_l;
   if(!list)
      return NULL;
      
   if(new_l = new_list())
      return new_l;
      
   new_l->first  = list->first;
   new_l->last   = list->last;
   new_l->qtd    = list->qtd;
   new_l->indice = list->indice;
   
   return new_l;
}

/*
 * Add element in the final list
 */
void push(int info, list* list)
{
   add(info, list);
}

/*
 * Remove the last element
 */
int pop(list* list)
{
   int info;
   
   if(!list || !list->qtd)
      return NULL;
      
   info = list->last->info;
   list->last = list->last->next;
   
   if(list->qtd == 1)
      list->first = list->last;
      
   list->qtd--;
      
   return info;
}

/*
 * Add element in the final list
 */
void enqueue(int info, list* list)
{
   add(info,list);
}

/*
 * Remove the first element
 */
int dequeue(list* list)
{
   int r;
   node* temp1 = NULL, temp2 = NULL;
   
   if(!list || !list->qtd)
      return NULL;
      
   temp1 = list->last;
      
   while(temp1 != list->first)
   {
      temp2 = temp1;
      temp1 = temp2->next;
   }
   
   r = temp1->info;
   free(temp1);
   
   list->first = temp2;
}
/*
 * Clear the list, after free list of memory
 */

void free_list(list* list)
{
   node* temp1, temp2;
   
   if(!list)
      return;
   temp1 = list->last;
   while(temp)
   {
      temp2 = temp1;
      free(temp1);
      temp1 = temp2->next;
   }
   
   free(list);
}




