import socket

client = socket.socket()
client.connect(('127.0.0.1', 12345))

while True:
    msg = input("Enter message: ")
    client.send(msg.encode())
    print("Server:", client.recv(1024).decode())