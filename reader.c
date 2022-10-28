// C Program for Message Queue (Reader Process)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
// structure for message queue
struct mesg_buffer {
    long mesg_type;
    char mesg_text[10];
} message;
int main()
{
    key_t key;
    int msgid;
    // ftok to generate unique key
    key = ftok(".", 1);
    // msgget creates a message queue
    // and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT);
    // msgrcv to receive message
    msgrcv(msgid, &message, sizeof(message), 1, 0);
    // display the message
    //printf("Data Received is : %s \n", message.mesg_text[0]);
    int a= atoi(message.mesg_text[0]);
    //printf("Data Received is : %s \n", message.mesg_text[1]);
    int b = atoi(message.mesg_text[1]);
    //printf("Data Received is : %s \n", message.mesg_text[2]);
    char c=message.mesg_text[2];
    int s;
    if(strcmp(c,"+")==0)
        s=a+b;
    if(strcmp(c,"-")==0)
        s=a-b;
    if(strcmp(c,"x")==0)
        s=a*b;
    if(strcmp(c,"/")==0)
        s=a/b;



    message.mesg_type = 1;
    message.mesg_text[0]=itoa(s);
    msgsnd(msgid, &message, sizeof(message), 0);
    // display the message
    printf("Data send is : %d \n", s);
    // to destroy the message queue
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}