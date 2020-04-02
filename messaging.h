/**
 * @Author: Abdullah Khalid
 * Description: a header-file defining messaging functions
 * Date : 2-4-2020
 */
#include<stdio.h>
#define ENDING_CHAR '\n'
#define STARTING_CHAR '\0'
void reciving(char *shm);
void send_message(char *sender,char *message, char *shm);
void stall_sending(char *shm);
void stall(char stalling_character, char *shm);
