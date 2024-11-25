import socket

client = socket.socket()
client.connect(('127.0.0.1', 12345))

# Get the number from the client
n = int(input("Enter a number: "))
client.send(str(n).encode())  # Send the number to the server

# Receive and print the factorial result
factorial = client.recv(1024).decode()
print(f"Factorial of {n} is {factorial}")

client.close()
