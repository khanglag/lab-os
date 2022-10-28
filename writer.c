// C Program for Message Queue (Writer Process)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>
// structure for message queue
struct mesg_buffer {
    long mesg_type;
    char mesg_text[10];
} message;
int main(int argc, char *argv[])
{
    key_t key;
    int msgid;
    // ftok to generate unique key
    key = ftok(".", 1);
    // msgget creates a message queue
    // and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT);
    message.mesg_type = 1;
    strcpy(message.mesg_text,argv);
    // msgsnd to send message
    //msgsnd(msgid, &message, sizeof(message), 0);
    //strcpy(message.mesg_text[1],argv[2]);
    // msgsnd to send message
    //msgsnd(msgid, &message, sizeof(message), 0);
    //strcpy(message.mesg_text[2],argv[3]);
    // msgsnd to send message
    msgsnd(msgid, &message, sizeof(message), 0);
    // display the message
    // for(int i=0;i<=2;i++){
    //  // msgrcv to receive message
    // }
    // printf("Data send is : %s \n",(char) message.mesg_text[0]);
    // printf("Data send is : %s \n",(char) message.mesg_text[1]);
    // printf("Data send is : %s \n",(char) message.mesg_text[2]);
    // msgrcv(msgid, &message, sizeof(message), 1, 0);
    // // display the message
    // printf("Data Received is : %s \n", message.mesg_text);
    return 0;
}