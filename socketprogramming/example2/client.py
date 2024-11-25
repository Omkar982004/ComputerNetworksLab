import socket

client = socket.socket()
client.connect(('127.0.0.1', 12345))

while True:
    msg = input("Enter string: ")
    client.send(msg.encode())
    response = client.recv(1024).decode()
    print("Server:", response)