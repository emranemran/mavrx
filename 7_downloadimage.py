import requests

url = 'http://www.digikey.com/-/media/Images/Header/logo_dk.png?la=en-US&ts=5b6b81dc-74b3-428d-8251-c96efbebec89'

response = requests.get(url, stream=True)

if response.status_code == 200:

	'''write to local file'''
	f = open('dk.png','wb')
	f.write(response.content)

	'''write to usb directory'''
	usb = open('/media/pi/B0F1-E352/dk.png','wb')
	usb.write(response.content)

	f.close()
	usb.close()
