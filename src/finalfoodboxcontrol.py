import time
import RPi.GPIO as GPIO
from Adafruit_IO import Client
ADAFRUIT_IO_USERNAME = "foodproject"
ADAFRUIT_IO_KEY = "aio_TPnU90PuhZd1ascY8snAF8SJoVHt"
aio = Client(ADAFRUIT_IO_USERNAME, ADAFRUIT_IO_KEY)
xbutton = aio.feeds('controlbox')
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
servoPIN = 17
GPIO.setup(22,GPIO.OUT)
GPIO.setup(27,GPIO.OUT)
GPIO.setup(servoPIN, GPIO.OUT)
p = GPIO.PWM(servoPIN, 50)
p.start(2.5)
try:
	while True:
		mybutton = aio.receive(xbutton.key)
		#print('button status', mybutton.value)
		#print ("----------")
		time.sleep(1)
		x=mybutton.value
		#print(type(x))
		x=int(x)	
		if x==1:
			p.ChangeDutyCycle(2.5)
			print("Lock opened")
			time.sleep(2)
		else:
			p.ChangeDutyCycle(7)
			print("lock closed")
			time.sleep(2)
except KeyboardInterrupt:
	p.stop()
	GPIO.cleanup()
		