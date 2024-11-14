import socket

client = socket.socket()
client.connect(('127.0.0.1', 12345))

# Get marks from the user
marks = int(input("Enter marks: "))
client.send(str(marks).encode())  # Send marks to the server

# Receive and print the grade from the server
grade = client.recv(1024).decode()
print("Grade:", grade)

client.close()
