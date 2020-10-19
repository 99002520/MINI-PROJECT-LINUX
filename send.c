// C Program for Message Queue (Writer Process) 
#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <string.h>

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

    printf("Enter account no : "); 
	gets(u1.ac_no); 

    
    printf("\nEnter the amount to be deposited :");
    scanf("%d",&u1.cash_amt);

	// ftok to generate unique key 
	key = ftok("progfile", 65); 

	// msgget creates a message queue 
	// and returns identifier 
	msgid = msgget(key, 0666 | IPC_CREAT); 
	u1.mesg_type = 1; 

	
	// msgsnd to send message 
	msgsnd(msgid, &u1, sizeof(u1), 0); 

	// display the message 
	printf("Data send is : %d %s \n", u1.cash_amt,u1.ac_no); 

	return 0; 
} 
