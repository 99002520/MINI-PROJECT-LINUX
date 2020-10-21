// C Program for Message Queue (Writer Process) 
#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <string.h>

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

    printf(" Welcome.. \n Please Enter your account number : "); 
	gets(stru1.account_number); 

    
    printf("\nEnter the amount to be deposited :");
    scanf("%d",&stru1.cash_amt);

	// ftok to generate unique key 
	key = ftok("progfile", 65); 

	// msgget creates a message queue 
	// and returns identifier 
	messagesgid = msgget(key, 0666 | IPC_CREAT); 
	stru1.message_type = 1; 

	
	// msgsnd to send message 
	msgsnd(messagesgid, &stru1, sizeof(stru1), 0); 

	// display the message 
	printf(" Data send Sucessfully... \n Data send is : %d %s \n", stru1.cash_amt,stru1.account_number); 

	return 0; 
} 
