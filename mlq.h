#ifndef MLQ
#define MLQ

#include "queue.h"

// The following definition for mlq_t was adapted from the Zybooks LA 10.11.1 Instructions 

typedef struct {
  queue_t * queues;
  int size;
} mlq_t;

// The following function definitions were adapted from the Zybooks LA 10.11.1 Instructions 

bool
mlq_initialize (mlq_t * mlqueue, int size);

void
mlq_release (mlq_t * mlqueue );

bool
mlq_enqueue ( mlq_t * mlqueue, char * item, int queue_num );

char *
mlq_dequeue ( mlq_t * mlqueue );

void
mlq_promote ( mlq_t * mlqueue );

bool
mlq_empty ( const mlq_t * mlqueue );

#endif 
