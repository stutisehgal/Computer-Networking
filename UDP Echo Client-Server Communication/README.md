To implement an UDP Echo Client-Server application, where the Client on establishing a connection with the Server, sends a string to the Server. The Server reads the string and echoes it back to the Client.

PROCEDURE:
- Server:
1. Include the necessary header files.
2. Create a socket using socket function with family AF_INET, type as SOCK_DGRAM.
3. Initialize server address to 0 using the bzero function.
4. Assign the sin_family to AF_INET, sin_addr to INADDR_ANY, sin_port to SERVER_PORT, a macro defined port number.
5. Bind the local host address to socket using the bind function.
6. Within an infinite loop, receive message from the client using recvfrom function, print it on the console and send (echo) the message back to the client using sendto function.

- Client:
1. Include the necessary header files.
2. Create a socket using socket function with family AF_INET, type as SOCK_DGRAM.
3. Initialize server address to 0 using the bzero function.
4. Assign the sin_family to AF_INET.
5. Get the server IP address from the console.
6. Using gethostbyname function assign it to a hostent structure, andassign it to sin_addr of the server address structure.
7. Within an infinite loop, read message from the console and send the message to the server using the sendto function.
8. Receive the echo message using the recvfrom function and print it on the console.
