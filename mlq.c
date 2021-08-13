#include "mlq.h"

bool mlq_initialize (mlq_t * mlqueue, int size){
   if (size <= 0){
      return false;
   }
   mlqueue->queues = (queue_t*)malloc(sizeof(queue_t) * size);
   if ((mlqueue->queues) == NULL){
      return false;
   }
   mlqueue->size = size; 
   for (int i = 0; i < size; i++){
      queue_initialize(&(mlqueue->queues[i]));
   }
   return true;
}


bool mlq_empty ( const mlq_t * mlqueue ){
   if ((mlqueue->size == 0) || (mlqueue->queues == NULL)){
      return true;
   }
   for (int i = 0; i < (mlqueue->size); i++){
      if (!(queue_empty(&(mlqueue->queues[i])))){
         return false;
      }
   }
   return true;
}
    
void mlq_release (mlq_t * mlqueue ){
   for (int i = 0; i < (mlqueue->size); i++){
      queue_clear(&(mlqueue->queues[i]));
   }
   mlqueue->size = 0;
   free(mlqueue->queues);
   mlqueue->queues = NULL;
}

bool mlq_enqueue ( mlq_t * mlqueue, char * item, int queue_num ){
   if ((queue_num < 0) || (queue_num >= (mlqueue->size))){
      return false;
   }
   return (queue_enqueue(&(mlqueue->queues[queue_num]), item));
}

char * mlq_dequeue ( mlq_t * mlqueue ){
   if ((mlqueue->size == 0) || (mlqueue->queues == NULL)){
      return NULL;
   }
   for (int i = 0; i < (mlqueue->size); i++){
      if (!queue_empty(&(mlqueue->queues[i]))){
         return queue_dequeue(&(mlqueue->queues[i]));
      }
   }
   return NULL;
}
   
   
void mlq_promote ( mlq_t * mlqueue ){
   if ((mlqueue->size == 0) || (mlqueue->queues == NULL)){
      return;
   }
   for (int i = 0; i < (mlqueue->size) - 1; i++){
      queue_merge(&(mlqueue->queues[i]), &(mlqueue->queues[i+1]));
   }
}
