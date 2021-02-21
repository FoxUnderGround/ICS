import serial
import pyautogui,time
time.sleep(3)

ser = serial.Serial('COM7')  # open serial port
print(ser.name)  
data = ''
byte = ''

while 1:
    byte = ser.read(1)
    if not((byte == b'\n') ^ (byte == b'\r')):
        data += byte.decode() 
    elif byte == b'\n':
        pyautogui.write(data)
        print(data)
        pyautogui.press('enter')
        data=''

ser.close() 