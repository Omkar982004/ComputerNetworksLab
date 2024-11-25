import socket

client = socket.socket()
client.connect(('127.0.0.1', 12345))

# Send the file name to the server
file_name = input("Enter file name: ")
client.send(file_name.encode())

# Receive the file contents or error message
response = client.recv(1024).decode()
print("Server response:", response)

client.close()
