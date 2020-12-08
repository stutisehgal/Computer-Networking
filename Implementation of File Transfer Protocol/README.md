Implementation of File Transfer Protocol, where the Client on establishing a connection with the Server sends the name of the file it wishes to access remotely. The Server then sends the contents of the file to the Client, where it is stored.

ALGORITHM:
- Server:
1. Create a socket with address family AFINET, type SOCK_STERAM and default protocol.
2. Initialize the socket and set its attributes.
3. Bind the server to socket using bind function.
4. Wait for the client request on request establish a connection using accept() function.
5. Read the source and destination files names from the client.
6. Open the source and destination files.
7. Read one line of source file and send it to client. Receive the line back from the client. Repeat until the end of the source file.
8. close the source and destination files. Close the connection.

- Client:
1. Create a socket with address family AFINET type SOCK_STREAM and default protocol.
2. Initialize the socket and set its attribute set required port number.
3. Connect to server using connect () function to initiate the request.
4. Send the source and destination file names to server.
5. Receive the string from the server and print it in the console. Send the string to the server. Repeat until the server terminates and connection.
