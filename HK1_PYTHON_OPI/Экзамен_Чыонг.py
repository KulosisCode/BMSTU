#Чыонг Ван Хао
#ИУ7И - 11Б
#Экзамен

import re

pattern = re.compile(r'([+/*-]?\s?\d+\s?[+/*-]?)+')
lst = []
length = 0
file_in = open("in.txt",'r')
while True:
	a = file_in.readline()
	if a == '':
		break
	length += 1
	isAdd = False
	matches = re.finditer(pattern, a)
	for match in matches:
		isAdd = True
		equa = a[match.span()[0]:match.span()[1]]
		answer = eval(equa.strip())
		if answer != int(answer):
			lst.append(-1)
		elif answer <= 0:
			lst.append(-1)
		else:
			answer = int(answer)
			lst.append(answer)
	if isAdd == False:
		lst.append(-1)
file_in.close()

file_in = open("in.txt",'r')
file_out = open("out.txt",'w')
whilecount = -1
while True:
	a = file_in.readline()
	if a == '':
		break
	whilecount += 1
	if whilecount == length - 1:
		file_out.write(a)
		break
	elif lst[whilecount + 1] != -1:
		file_out.write(a[:-1]*lst[whilecount + 1] + '\n')
	else:
		file_out.write(a)

file_in.close()
file_out.close()