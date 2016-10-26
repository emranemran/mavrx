import ntplib, datetime, subprocess

try:
	t = ntplib.NTPClient()
	asia_ntp = datetime.datetime.utcfromtimestamp(t.request('asia.pool.ntp.org').tx_time)
	
	print 'current unset time: %s' % (datetime.datetime.now())
	print 'asia ntp time: %s' % asia_ntp

	subprocess.call(['sudo', 'date', '--set', ' {}'.format(asia_ntp)])

except:
	print 'Error'


