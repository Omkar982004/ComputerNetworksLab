import socket

client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

while True:
    # Send message to server
    message = input("You: ")
    client.sendto(message.encode(), ('127.0.0.1', 12345))
    
    # Receive reply from server
    reply, _ = client.recvfrom(1024)
    print("Server:", reply.decode())
    if reply.decode().lower() == 'bye':
        break

client.close()
