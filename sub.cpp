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
		char *portName       = argv[1];
		//Publisher Message
		void *subC          = zmq_ctx_new();
		//Initialize Subscriber Context		
		void *subS          = zmq_socket(subC,ZMQ_SUB);
		char ip[100]         ="tcp://127.0.0.1:";
		char sockAddr[200];		
		char temp[200];
		int  numrecv         = -1;

		sprintf(sockAddr,"%s%s",ip,portName);
		printf("\nSocket Address  : %s\n",sockAddr);
		printf("Port Number     : %s\n\n",portName);
		
		//Initialize Subscriber Bind
		int rc = zmq_bind(subS,sockAddr);
		printf("ZMQ Bind Status in Subscriber : %d\n\n",rc);		
		//ZMQ Subscriber filter message
		zmq_setsockopt(subS,ZMQ_SUBSCRIBE,"",0);

		do
		{
		    //ZMQ Send for publisher using no block mode (async)
		    numrecv           = zmq_recv(subS,temp,200,ZMQ_NOBLOCK);
		    if (numrecv > -1) printf("Content : %s | Zmq Recv Return Call : %d\n",temp,numrecv);
		}while(1);

		zmq_close(subS);
		printf("Socket at address : %s ... Terminated\n",sockAddr);	
		zmq_ctx_term(subC);
		printf("Context ... Terminated\n");
		
		return 0;
}
