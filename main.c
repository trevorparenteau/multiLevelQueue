#include "mlq.h"

#define MAX_ENTRY 63

int main(int argc, char* argv[]) {
   
   if (argc < 2){
      printf("ERROR: Requires number of queues\n");
      return 1;
   }
   
   mlq_t userMLQ;
   int numQueues;
   
   sscanf(argv[1], " %d", &numQueues); 
 
   mlq_initialize(&userMLQ, numQueues);
 
   char* userCommand = (char*)malloc(sizeof(char) * MAX_ENTRY);
   
   scanf("%s", userCommand);
   
   if ((strcmp(userCommand, "quit") != 0) &&
       (strcmp(userCommand, "enqueue") != 0) &&
       (strcmp(userCommand, "dequeue") != 0) &&
       (strcmp(userCommand, "promote") != 0)){
          printf("ERROR: Invalid command\n");
          scanf(" %s", userCommand);
       }
       
   char* valRead = (char*)malloc(sizeof(char) * (MAX_ENTRY + 3));
   
   while ((strcmp(userCommand, "quit") != 0) && (feof(stdin) == 0)){
      if (strcmp(userCommand, "enqueue") == 0){
         int index;
         char * entry = (char*)malloc(sizeof(char) * MAX_ENTRY);
         
         fgets(valRead, (MAX_ENTRY + 4), stdin);
            
         if (valRead == NULL){
            printf("ERROR: Incorrect inputs for enqueue command\n");
            scanf(" %s", userCommand);
         }
         
         int didRead;
         didRead = sscanf(valRead, "%d %s", &index, entry);
         
         if (didRead != 2){
            printf("ERROR: Incorrect inputs for enqueue command\n");
            scanf(" %s", userCommand);
         }
         
         if ((index < 0) || (index > ((&userMLQ)->size))){
             printf("ERROR: Invalid queue for enqueue command\n");
             scanf(" %s", userCommand);
         }
         else if (!mlq_enqueue(&userMLQ, entry, index)){
            printf("ERROR: Invalid queue for enqueue command\n");
            scanf(" %s", userCommand);
         }
         else {
            scanf(" %s", userCommand);
         }
      }
      else if (strcmp(userCommand, "dequeue") == 0){
         if (mlq_empty(&userMLQ)){
         printf("ERROR: Queue empty on dequeue command\n");
         scanf(" %s", userCommand);
         }
         else {
            printf("%s\n", mlq_dequeue(&userMLQ));
            scanf(" %s", userCommand);
         }
      }
      else if (strcmp(userCommand, "promote") == 0){
         mlq_promote(&userMLQ);
         scanf(" %s", userCommand);
      }
      else {
         printf("ERROR: Invalid command\n");
         scanf(" %s", userCommand);
      }
   }

   if (strcmp(userCommand, "enqueue") == 0){
         int index;
         char * entry = (char*)malloc(sizeof(char) * MAX_ENTRY);
         if (valRead == NULL){
            printf("ERROR: Incorrect inputs for enqueue command\n");
            scanf(" %s", userCommand);
         }
         
         sscanf(valRead, "%d %s", &index, entry);
         
         if ((index < 0) || (index > ((&userMLQ)->size))){
             return 0;
         }
         else if (!mlq_enqueue(&userMLQ, entry, index)){
            return 0;
         }
         else {
            return 0;
         }
      }
      else if (strcmp(userCommand, "dequeue") == 0){
         if (mlq_empty(&userMLQ)){
         printf("ERROR: Queue empty on dequeue command\n");
         return 0;
         }
         else {
            printf("%s\n", mlq_dequeue(&userMLQ));
            return 0;
         }
      }
      else if (strcmp(userCommand, "promote") == 0){
         mlq_promote(&userMLQ);
         return 0;
      }
   
   return 0;
}
