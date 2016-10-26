import requests
import struct

url = 'https://mavrx-public.s3.amazonaws.com/float.bin'
response = requests.get(url)

if response.status_code == 200:
	'''read response content as big-endian float'''
	num, = struct.unpack('>f',response.content)
	print num
	
