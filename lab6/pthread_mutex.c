#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <>

pthread_t tid[2];
int counter;
pthread_mutex_t lock;

void* doSomeThing(void *arg) {
  pthread_mutex_lock(&lock);

  unsigned long i = 0;
  counter += 1;
  printf("\n Job %d started\n", counter);
  
  for(i = 0; i<(0xFFFFFFF); i++);
  printf("\n Job %d finished\n", counter);

  pthread_mutex_unlock(&lock);
  
  return NULL;
}


int main(void)
{
  int i = 0;
  int err;

  while(i < 2) {
    err = pthread_create(&tid
			 }
