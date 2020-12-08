There is a single host. The IP address of any Client in the network is given as input and the corresponding hardware address is got as the output.
Address Resolution Protocol (ARP)  is implemented through this program. The IP address of any Client is given as the input. The ARP cache is looked up for the corresponding hardware address which is returned as the output. Before compiling that Client is pinged.

ALGORITHM:
- Server:
1. Create UDP socket
2. Blind the socket to server address
3. Wait until datagram packet arrives from client
4. Process the datagram packet and send current time
5. Go back to Step 3.

- Client:
1. Create UDP socket
2. Wait until the connection is established
3. Then wait till response from server is received
4. Process reply and go back to step 2, if necessary
5. Close socket descriptor and exit.
