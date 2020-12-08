To implement a concurrent TCP day-time server.

Methodology/Algorithm:

- Server:
1. Include necessary files.
2. We need to create a socket using Socket function with the family AF_INET, and type as SOCK_STREAM.
3. Initialize the server address at 0.
4. Assign the AF_INET, address and the port number.
5. Bind the address and port using bind function.
6. Listen on the socket till connection is made with client.
7. Within an infinite loop, using the recvfrom function receive message from client and print it on the Console.

- Client:
1. Include the header files.
2. Create socket with AF_INET for IPv4 connection and SOCKSTREAM for TCP connection.
3. Initialize server address to 0.
4. Assign sin_family to AF_INET.
5. Get Server IP address and port number from console.
6. Using gethostbyname function assign it to a hostent structure. And assign it to sin_addr of the server address structure.
7. Request connection from server.
8. Within an infinite loop, read message from console and send message to server.
