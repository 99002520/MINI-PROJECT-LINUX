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
	long message_type; 
	char account_number[100];
    int cash_amt; 
} stru1; 

int main() 
{ 
	key_t key; 
	int messagesgid;
    int err;
    int counter=4;
    // ftok to generate unique key 
	key = ftok("progfile", 65); 

	// msgget creates a message queue 
	// and returns identifier 
	messagesgid = msgget(key, 0666 | IPC_CREAT); 

	// msgrcv to receive message 
	msgrcv(messagesgid, &stru1, sizeof(stru1), 1, 0); 

	// display the message 
	 

    void* update_cash(void *arg)
{
    pthread_mutex_lock(&lock);

    unsigned long i = 0;
    printf("\n Cash updating.. Please Wait...\n");
    balance+=stru1.cash_amt;
    printf("\n Balance Amount : %d\n",balance);
    for(i=0; i<(0xFFFFFFFF);i++);
    printf("\n Updation completed successfully.. Thank You..\n");
    pthread_mutex_unlock(&lock);
    printf("+ %d to %s \n", stru1.cash_amt, stru1.account_number);

    return NULL;
}
    while(counter>0){
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n Sorry!!! \n Mutex initilation failed..\n");
        return 1;
    }
    err = pthread_create(&(tid), NULL, &update_cash, NULL);
        if (err != 0)
            printf("\n Sorry!!! \n Thread creation failed... ");
            counter--;}
    pthread_join(tid, NULL);
    //pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock);

    // to destroy the message queue 
	msgctl(messagesgid, IPC_RMID, NULL); 

	return 0; 
} 
