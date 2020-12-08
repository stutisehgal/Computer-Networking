There are two hosts, Client and Server. The Client sends a command to the Server, which executes the command and sends the result back to the Client. 
Remote Command execution is implemented through this program using which Client is able to execute commands at the Server. Here, the Client sends the command to the Server for remote execution. The Server executes the command and the send result of the execution back to the Client.

ALGORITHM:
- SERVER:
1. Include all the necessary header files
2. Create a socket() with parameters as AF_INET, SOCK_DGRAM, 0
3. Create a buffer of size 1000 to store the incoming command
4. Create and initialise the serverAddress to the following :
a. sin_family to AF_INET
b. sin_addr.s_addr = htonal(INADDR_ANY)
c. sin_port to 1234
5. Using the bind(), bind the socket with the serverAddress
6. Enter the infinite loop and perform the following :
a. set the buffer to 0 using memset()
b. receive command from the client side using the recvfrom()
c. execute the command using the system()
d. send acknowledgement to the client side after executing the command
7. Close the socket()

- CLIENT:
1. Include all the necessary header files
2. Create a socket() with parameters as AF_INET, SOCK_DGRAM, 0
3. Create a buffer of size 1000 to store the acknowledgment message from the server
4. Create and initialize the serverAddress to the following :
a. sin_family to AF_INET
b. sin_addr.s_addr = inet(“127.0.0.1”)
c. sin_port to 1234
5. Using the bind(), bind the socket with serverAddress
6. Enter the infinite loop and perform the following :
a. takes the command from the user console
b. stores it in the buffer array
c. using the sendto(), sends buffer to the server side
d. receives the particular acknowledgement from the server side after the command was executed and shows the message on the output console
7. Close the socket()
