m = 0
n = 0
while (m <= 0) or (n <= 0) or (m < n) :
	m = int(input("Enter m: "))
	n = int(input("Enter n: "))
tm = m
tn = n
h = m % n
while (h != 0) and (h != 1) :
	h = tm % tn 
	tm = tn
	tn = h
print("in h:",h)
if h == 0 :
	print(tm)
else :
	print(tn)

