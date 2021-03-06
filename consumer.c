/**
 * @Author: Abdullah Khalid
 * Description: an implementation to consumer in ipc
 * Date : 2-4-2020
 */
#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include"err_checking.h"
#include"messaging.h"

#define SH_BUFFER_SIZE 128
char *sender;
int main(int argc, char *argv[]){
	key_t key = 12345; // set a key for the shared resource
	int shmid = shmget(key, SH_BUFFER_SIZE, 0666); //getting the shared memory id
	ERRCHECKER_shared_memory_getting(shmid); // check for shared memory getting errors
	char *shm = shmat(shmid, NULL , 0); // getting the shared memory pointer

	ERRCHECKER_shared_memory_atteching(shm); // check for shared memory attaching errors

	if (argc == 1)
		sender = "client";
	else if (argc == 2)
		sender = argv[1];
	while(1)
	{
		reciving(shm);
		char message[100];
		printf("%s> ",sender);
		gets(message);
		send_message(sender,message, shm);
	}
	return 0;
}

