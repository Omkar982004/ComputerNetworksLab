#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 12345
#define BUFFER_SIZE 1024

using namespace std;

int main() {
    // Create socket
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd == -1) {
        perror("Socket creation failed");
        return -1;
    }

    // Define server address
    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        return -1;
    }

    // Connect to the server
    if (connect(client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return -1;
    }

    cout << "Connected to the server. You can now send messages.\n";

    char buffer[BUFFER_SIZE];
    while (true) {
        // Get user input
        cout << "Enter message (or type 'datetime' for current time): ";
        cin.getline(buffer, sizeof(buffer));

        // Send the message to server
        send(client_fd, buffer, strlen(buffer), 0);

        // Receive server's response
        int recv_len = recv(client_fd, buffer, sizeof(buffer), 0);
        if (recv_len < 0) {
            perror("Receive failed");
            break;
        }

        // Null terminate the received message
        buffer[recv_len] = '\0';

        cout << "Response from server: " << buffer << endl;
    }

    // Close the connection
    close(client_fd);
    return 0;
}
