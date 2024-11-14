import socket

server = socket.socket()
server.bind(('', 12345))
server.listen(1)
print("Server is listening...")

client, addr = server.accept()
print("Connected to:", addr)

while True:
    msg = client.recv(1024).decode()
    if not msg:
        break
    print("Client:", msg)
    
    # Check if the message is a palindrome
    if msg == msg[::-1]:
        response = "Palindrome"
    else:
        response = "Not Palindrome"
    
    client.send(response.encode())

client.close()