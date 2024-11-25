import socket

server = socket.socket()
server.bind(('', 12345))
server.listen(1)
print("Server is listening...")

client, addr = server.accept()
print("Connected to:", addr)

while True:
    n = int(client.recv(1024).decode())  # Receive the integer n from the client
    
    for i in range(n, 0, -1):
        client.send(('*' * i).encode())  # Send the sequence of '*' to the client
        client.send(b'\n')  # Send a newline to separate the lines

client.close()
