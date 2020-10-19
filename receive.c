// C Program for Message Queue (Reader Process) 
#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid;
pthread_mutex_t lock;
int balance =1000;

// structure for message queue 
struct user { 
	long mesg_type; 
	char ac_no[100];
    int cash_amt; 
} u1; 

int main() 
{ 
	key_t key; 
	int msgid;
    int err;
    int counter=4;
    // ftok to generate unique key 
	key = ftok("progfile", 65); 

	// msgget creates a message queue 
	// and returns identifier 
	msgid = msgget(key, 0666 | IPC_CREAT); 

	// msgrcv to receive message 
	msgrcv(msgid, &u1, sizeof(u1), 1, 0); 

	// display the message 
	 

    void* update_cash(void *arg)
{
    pthread_mutex_lock(&lock);

    unsigned long i = 0;
    printf("\n Cash updating\n");
    balance+=u1.cash_amt;
    printf("\nBalance : %d\n",balance);
    for(i=0; i<(0xFFFFFFFF);i++);
    printf("\nUpdation completed successfully\n");
    pthread_mutex_unlock(&lock);
    printf("+ %d to %s \n", u1.cash_amt, u1.ac_no);

    return NULL;
}
    while(counter>0){
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n Mutex init failed\n");
        return 1;
    }
    err = pthread_create(&(tid), NULL, &update_cash, NULL);
        if (err != 0)
            printf("\nThread creation failed");
            counter--;}
    pthread_join(tid, NULL);
    //pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock);

    // to destroy the message queue 
	msgctl(msgid, IPC_RMID, NULL); 

	return 0; 
} 
