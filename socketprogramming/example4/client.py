import socket

client = socket.socket()
client.connect(('127.0.0.1', 12345))

# Get input from the client
n = int(input("Enter a number: "))
client.send(str(n).encode())  # Send the number to the server

# Receive and print the sequence of '*' from the server
while True:
    response = client.recv(1024).decode()
    if not response:
        break
    print(response, end="")
