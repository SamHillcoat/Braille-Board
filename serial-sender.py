import serial
from time import sleep


def read_file_data():
    f = open("states.txt", "r")
    data = f.read()
    data = data.split()
    for i in range(len(data)):
        data[i] = int(data[i])
    return data
    # print(data)


def send_serial(data):
    string = "".join(str(e) for e in data)
    print(string)
    s = serial.Serial('/dev/ttyUSB0')  # Change USBx value to current serial port
    s.write(bytes(string + "/", 'utf-8'))
    sleep(0.5)


while True:
    data = read_file_data()
    send_serial(data)
