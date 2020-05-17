#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>



using namespace std;

sem_t sem_mother, sem_children;

pthread_mutex_t mutex_thread;

int children_waiting_count;

int m_g;
int n_g;
int t_g;

int pots_status_g[100];

int child_to_call = 0;


void delay() {
  sleep(1);
}

int ready_to_eat(int id){

     int i;
     int pot = -1;
     char message[80];
     int exit_flag = 0;

   sem_wait(&sem_children);

   while (1) {
   
     pthread_mutex_lock(&mutex_thread);

     int two_exist = 0, all_zero = 0 ;
     
     
     for (i = 0; i < m_g && pots_status_g[i] != 2; i++);
     if (i < m_g) {
       two_exist = 1;
       pot = i;
     }
     

     for (i = 0; i < m_g && pots_status_g[i] == 0; i++);
     if (i == m_g)
       all_zero = 1;
     
     if (two_exist == 1) {
       sprintf(message, "%*sBaby eagle %d is eating using feeding pot %d.\n", id, "", id, pot);
       pots_status_g[pot] = 1;       
       exit_flag = 1;
     }
     else if (all_zero == 1) {
       if (child_to_call == 0) {
       sprintf(message, "%*sBaby %d see all feeding pots are empty and wakes up the mother.\n", id, "", id);
       child_to_call = id;
       }
       else {
	 sprintf(message, "");
       }
       exit_flag = 0;
     }
     else {
       sprintf(message, "");
       exit_flag = 0;
     }
     
        write(1, message, strlen(message));    
     pthread_mutex_unlock(&mutex_thread);
     delay();
     if (exit_flag == 1) break;
   }
   sem_post(&sem_children);
   return pot;
   
 };


void finish_eating(int id, int pot) {
  char message[80];
  pthread_mutex_lock(&mutex_thread);
  pots_status_g[pot] = 0;
  sprintf(message, "%*sBaby eagle %d finishes eating.\n", id, "", id);
  write(1, message, strlen(message));
  pthread_mutex_unlock(&mutex_thread);
};

void * children_actions(void *children_id) {
  int id = *(int *)children_id;
  char message[80];

  sprintf(message, "%*sBaby eagle %d started.\n", id, "", id);
  write(1, message, strlen(message));

  int pot;
  
  while (1) {
    delay();
    pot = ready_to_eat(id);
    delay();
    finish_eating(id, pot);
  }
};




int main(int argc, char **argv) {
  int m, n, t; // m: feeding pots; n: baby eagles; t: refill times
  m_g =m = atoi(argv[1]);
  n_g = n = atoi(argv[2]);
  t_g = t = atoi(argv[3]);
  //  cout << " m: " << m << " n: " << n << " t: " << t << endl;
  srand(time(NULL));
  
  children_waiting_count = 0;

  int i;

  


    for (i = 0; i < m; i++) {
      pots_status_g[i] = 2; // 0: empty; 1:occupied, 2:available;
    }
    
  

  pthread_t thread_mother;
  pthread_t thread_childrean[n];

  int children_ids[n];
  

  for (i = 0; i < n; i++) {
    children_ids[i] = i + 1;
    pthread_create(&thread_childrean[i], NULL, children_actions, (void *)&children_ids[i]);
  }
  
  sem_init(&sem_children, 0, m);
  sem_init(&sem_mother, 0, 1);


  for (i = 0; i < n; i++)
    pthread_join(thread_childrean[i], NULL);

  
  return 0;
    
  

}
