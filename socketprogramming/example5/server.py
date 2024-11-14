import socket
import math

server = socket.socket()
server.bind(('', 12345))
server.listen(1)
print("Server is listening...")

client, addr = server.accept()
print("Connected to:", addr)

while True:
    n = int(client.recv(1024).decode())  # Receive the integer n from the client
    factorial = math.factorial(n)  # Calculate the factorial
    client.send(str(factorial).encode())  # Send the factorial result back to the client

client.close()
