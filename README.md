# Minitalk

Minitalk is a simple communication program consisting of a client and a server. The server receives messages from the client via UNIX signals (SIGUSR1 and SIGUSR2) and displays them.

## Mandatory Part

### Requirements
- The server must start first and display its PID (Process ID) upon launch.
- The client requires two parameters:
  - The server's PID.
  - The string to send to the server.
- The client sends the specified string to the server.
- Upon receiving the string, the server prints it promptly. 
- The server must handle multiple client messages consecutively without needing a restart.
- Communication between the client and server is done exclusively using UNIX signals SIGUSR1 and SIGUSR2.

### Implementation Details

#### Server

1. **Starting the Server:**
   - The server program starts and prints its PID to the console.

2. **Receiving Messages:**
   - The server listens for incoming messages sent via SIGUSR1 and SIGUSR2 signals.
   - It decodes the signals into characters to reconstruct the original string sent by the client.

3. **Printing Messages:**
   - The server prints the received message to the console as soon as it is fully received.

4. **Handling Multiple Clients:**
   - The server can handle messages from multiple clients in sequence without requiring a restart.

#### Client

1. **Sending Messages:**
   - The client sends a string to the server using the server's PID and the string as command-line arguments.
   - The string is encoded into SIGUSR1 and SIGUSR2 signals and sent to the server.

### Usage

#### Compile the Programs

To compile both the server and client programs, run the following commands:

```sh
make
```

#### Start the Server

To start the server, run the following command:

```sh
./server
```

The server will display its PID upon launch.

#### Send Messages from the Client

To send a message from the client to the server, run the following command:

```sh
./client [SERVER_PID] [MESSAGE]
```
