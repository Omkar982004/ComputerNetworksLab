import socket

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(('127.0.0.1', 12345))
server.listen(1)
print("Server is listening for connections...")

client, addr = server.accept()
print("Client connected:", addr)

while True:
    # Receive message from client
    message = client.recv(1024).decode()
    if message.lower() == 'bye':
        break
    print("Client:", message)
    
    # Send reply to client
    reply = input("You: ")
    client.send(reply.encode())

client.close()
