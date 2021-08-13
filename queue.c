#include "queue.h"

// queue_initialize has the same implementation as written in CA 10.9.1 written by Trevor and Jay

void queue_initialize (queue_t * queue){
   queue->head = NULL;
   queue->tail = NULL;
}

// queue_empty has the same implementation as written in CA 10.9.1 written by Trevor and Jay

bool
queue_empty (const queue_t * queue){
   if (queue->head == NULL){
      return true;
   }
   else return false;
}


// queue_enqueue has the same implementation as written in CA 10.9.1 written by Trevor and Jay

bool queue_enqueue (queue_t * queue, char * item){
   node_t* newNode = (node_t*)malloc(sizeof(node_t));
   if (newNode == NULL){
      return false;
   }
   newNode->data = item;
   newNode->next = NULL;
   if (queue_empty(queue)){
      queue->head = newNode;
      queue->tail = newNode;
      return true;
   }
   queue->tail->next = newNode; 
   queue->tail = newNode;
   return true;
}


// queue_dequeue has the same implementation as written in CA 10.9.1 written by Trevor and Jay

char * queue_dequeue (queue_t * queue){
   if (queue_empty(queue)){
      return NULL;
   }
   char* firstString = queue->head->data;
   node_t* temp = queue->head->next; 
   free(queue->head);
   queue->head = temp;
   return firstString;
}

void queue_merge (queue_t * front, queue_t * rear ){
   if (queue_empty(front)){
      if (queue_empty(rear)){
         return;
      }
      front->head = rear->head;
      front->tail = rear->tail;
      rear->head = NULL;
      rear->tail = NULL;
   }
   else if (queue_empty(rear)){
      return;
   }
   else {
      front->tail->next = rear->head;
      front->tail = rear->tail;
      rear->head = NULL;
      rear->tail = NULL;
   }
}

void queue_clear (queue_t * queue){
   if (queue_empty(queue)){
      return;
   }
   while (queue->head->next != NULL){
      node_t* next = queue->head->next;
      free(queue->head);
      queue->head = next; 
   }
   free(queue->head);
   queue->head = NULL;
   queue->tail = NULL;
}
      
