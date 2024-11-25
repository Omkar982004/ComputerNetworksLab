import socket
import time
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
    
    # Send back date-time or echo message
    response = time.ctime() if msg.lower() == "datetime" else msg
    client.send(response.encode())

client.close()