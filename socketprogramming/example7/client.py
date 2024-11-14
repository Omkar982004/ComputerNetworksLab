import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(('127.0.0.1', 12345))

while True:
    # Send message to server
    message = input("You: ")
    client.send(message.encode())
    
    # Receive reply from server
    reply = client.recv(1024).decode()
    if reply.lower() == 'bye':
        break
    print("Server:", reply)

client.close()
