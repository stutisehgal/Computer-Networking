A simple TCP/IP program in C language for both server and client side of the communication.

PROCEDURE:
- SERVER:
1. Create a socket with the socket () function with domain as AF_INET, type as SOCK_STREAM and protocol as 0 for Internet Protocol.
2. Forcefully attach socket to the port 8080 with setsockopt () function. This helps in manipulating options for the socket referred by the file descriptor sockfd and helps in reuse of address and port.
3. After creation of the socket, bind function binds the socket to the address and port number specified in addr (custom data structure). In the code, we bind the server to the localhost, hence we use INADDR_ANY to specify the IP address.
4. Listen () function puts the server socket in a passive mode, where it waits for the client to approach the server to make a connection. The backlog, defines the maximum length to which the queue of pending connections for sockfd may grow. If a connection request arrives when the queue is full, the client may receive an error with an indication of ECONNREFUSED.
5. Accept () function extracts the first connection request on the queue of pending connections for the listening socket, sockfd, creates a new connected socket, and returns a new file descriptor referring to that socket. At this point, connection is established between client and server, and they are ready to transfer data.
6. Use send () function to send message to the client once the connection is established.
7. Close the socket using the close () function.


- CLIENT:
1. Create a socket with the socket () function with domain as AF_INET, type as SOCK_STREAM and protocol as 0 for Internet Protocol.
2. Forcefully attach socket to the port 8080 with setsockopt () function. This helps in manipulating options for the socket referred by the file descriptor sockfd and helps in reuse of address and port.
3. The connect () system call connects the socket referred to by the file descriptor sockfd to the address specified by addr. Server’s address and port is specified in addr.
4. Check the value from the connect () function. If it is -1, some error has occurred and connection could not be established successfully.
5. Using the recv () function, client gets appropriate message from server and stores it in buffer.
6. Use send () function to send message to the server once the connection is established.
7. Close the socket using the close () function.
