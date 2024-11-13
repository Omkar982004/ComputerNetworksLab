#include <iostream>
#include <cstring>
#include <ctime>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 12345
#define BUFFER_SIZE 1024

using namespace std;

int main() {
    // Create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket creation failed");
        return -1;
    }

    // Define server address
    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) < 0) {
        perror("Listen failed");
        return -1;
    }

    cout << "Server is listening on port " << SERVER_PORT << "...\n";

    // Accept incoming client connection
    sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
    if (client_fd < 0) {
        perror("Client connection failed");
        return -1;
    }

    cout << "Client connected. Waiting for messages...\n";

    char buffer[BUFFER_SIZE];
    while (true) {
        memset(buffer, 0, sizeof(buffer));

        // Receive message from client
        int recv_len = recv(client_fd, buffer, sizeof(buffer), 0);
        if (recv_len < 0) {
            perror("Receive failed");
            break;
        }

        cout << "Received from client: " << buffer << endl;

        // Check if client requested date-time service
        if (strcmp(buffer, "datetime") == 0) {
            // Send current date-time to client
            time_t now = time(0);
            char* dt = ctime(&now);
            send(client_fd, dt, strlen(dt), 0);
        } else {
            // Echo the message back to client
            send(client_fd, buffer, strlen(buffer), 0);
        }

        cout << "Message sent to client: " << buffer << endl;
    }

    // Close the connection
    close(client_fd);
    close(server_fd);
    return 0;
}
