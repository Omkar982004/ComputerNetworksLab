import socket

server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server.bind(('127.0.0.1', 12345))
print("Server is listening...")

while True:
    # Receive message from client
    message, addr = server.recvfrom(1024)
    print("Client:", message.decode())
    
    # Send reply to client
    reply = input("You: ")
    server.sendto(reply.encode(), addr)
    if reply.lower() == 'bye':
        break

server.close()
