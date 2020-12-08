To create a Full Duplex Chat using TCP/IP Protocol so that client and server can send and receive messages simultaneously.

ALGORITHM:
- SERVER:
1. Include the necessary header files
2. Create a socket using the socket()
a. sin_family as AF_INET
b. sin_port as htons(1244)
c. sin_addr.s_addr = INADDR_ANY
3. Using the bind(), connect the specified port and the socket
4. Using the listen(), the server waits for requests from the client side from any address
5. When request is received it is accepted by the server using the accept()
6. Now, we enter the infinite loop,
a. take message input from console that is to be sent to the client side
b. server then sends the message to the client using send()
c. server then waits for messages from the client side using recv()
d. prints the message received from the client to the console
7. Close the socket

- CLIENT:
1. Include the necessary header files
2. Create a socket using the socket()
a. sin_family as AF_INET
b. sin_port as htons(1244)
c. sin_addr.s_addr = INADDR_ANY
3. Use the connect(), join the client socket to the server address
4. Now, we enter the infinite loop,
a. using the recv(), the client waits for the server’s message
b. after receiving the message, it is displayed on the console
c. now, we scan the message to be sent to the server side from the console using the scanf()
d. we then send the scanned message to the server side using send()
5. Close the socket
