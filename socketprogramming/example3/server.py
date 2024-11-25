import socket

server = socket.socket()
server.bind(('', 12345))
server.listen(1)
print("Server is listening...")

client, addr = server.accept()
print("Connected to:", addr)

while True:
    # Receive the file name from the client
    file_name = client.recv(1024).decode()
    
    try:
        with open(file_name, 'r') as file:
            content = file.read()
            client.send(content.encode())  # Send the file content
    except FileNotFoundError:
        client.send(b"File not found")  # If file doesn't exist
    
client.close()
