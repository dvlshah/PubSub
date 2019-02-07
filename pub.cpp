#include <zmq.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <string> 

using namespace std;

int main(int argc, char** argv)
{	
		//Port Number
		char *portName     = argv[1];
		//Publisher Message		
		char *pubMsg       = argv[2];		
		//Initialize publisher context		
		void *pubC         = zmq_ctx_new();
		//Initialize publisher socket  		
		void *pubS         = zmq_socket(pubC,ZMQ_PUB);
		int  numsend 	    = 0;
		int  msg_counter    = 0;
		//Initialize ip as localhost		
		char ip[100]        = "tcp://127.0.0.1:";		
		char sockAddr[200];
		char send_msg[100];

		//Socket address - tcp:127.0.0.1:PORT_NO
		sprintf(sockAddr,"%s%s",ip,portName);

		printf("\nSocket Address    : %s\n",sockAddr);
		printf("Port Number       : %s\n",portName);
		printf("Publisher Message : %s\n\n",pubMsg);
		
		//ZMQ Connect for publisher
		int  rc      = zmq_connect(pubS,sockAddr);
		printf("ZMQ Connect Status in Publisher : %d\n",rc);		

		do 
		{
			msg_counter     = msg_counter + 1;			
			sprintf(send_msg,"%s%d",pubMsg,msg_counter);
			//ZMQ Send for publisher using no block mode (async)
			numsend         = zmq_send(pubS,send_msg,strlen(send_msg)+1,ZMQ_NOBLOCK);
			if (numsend > -1) printf("Content : %s | Zmq Send Return Call : %d\n",send_msg,numsend);
			sleep(2);
		
		}
		while(1);

		zmq_close(pubS);
		printf("Socket Closed\n");	
		zmq_ctx_term(pubC);
		printf("Context Closed\n");

		return 0;
}
