import socket

server = socket.socket()
server.bind(('', 12345))
server.listen(1)
print("Server is listening...")

client, addr = server.accept()
print("Connected to:", addr)

# Define grade records
def get_grade(marks):
    if marks >= 90:
        return "Grade S"
    elif marks >= 80:
        return "Grade A"
    elif marks >= 70:
        return "Grade B"
    elif marks >= 60:
        return "Grade C"
    elif marks >= 50:
        return "Grade D"
    else:
        return "Fail"

while True:
    marks = int(client.recv(1024).decode())  # Receive marks from client
    grade = get_grade(marks)  # Determine grade based on marks
    client.send(grade.encode())  # Send grade back to client

client.close()
