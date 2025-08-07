from gpiozero import DistanceSensor
from time import sleep
from gpiozero.tones import Tone
from mfrc522 import SimpleMFRC522
from gpiozero import TonalBuzzer

sensor = DistanceSensor(21,20)
people = 0
flag = 0

lst1 = [242.32,253.34,810.2]
lst2 = [242.32,242.32,242.32]

b = TonalBuzzer(4)

user = 702470292822

while True:
    sleep(0.2)
    print(sensor.distance)
    if sensor.distance < 0.1 and flag == 0:
        flag = 1
        if SimpleMFRC522().read()[0] == user:
            print('open')
            for i in range(3):
                b.play(lst1[i])
                sleep(0.2)
                b.stop()
        else:
            print('close')
            for i in range(3):
                b.play(lst2[i])
                sleep(0.2)
                b.stop()
            b.stop()
            
    if sensor.distance > 0.1 and flag == 1:
        flag = 0#people went
        people += 1
    
    print(people)
    




