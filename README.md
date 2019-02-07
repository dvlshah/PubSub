# PubSub

A publisher - subscriber pattern written in C++ using ZeroMQ framework. 

This code is written for one subscriber - multiple publisher use case. Subscriber does the bind and
publisher does the connect. For the other case, simply interchange bind-connect in sub-pub. 

Pub Sub Model is aimed at scalability of sending messages to thousands of end points without the fear of message getting discarded. 
Known as fire and forget service, once the publisher sends the message it does not wait for the acknowledgement from the reciever. The message queue buffer handles the message and will make sure at some point of time in future the subscriber will recieve the message.
