import matplotlib.pyplot as plt
import numpy as np

# h1 = 10*np.random.rand(6)
# h2 = 10*np.random.rand(6)
# h3 = 10*np.random.rand(6)
# pos = np.arange(1,len(h1)+1)
# wide = 0.3
# plt.bar(pos,h1,width = wide)
# plt.bar(pos + wide,h2,width = wide, color = 'r')
# plt.bar(pos + 2*wide, h3, width = wide, color = 'g')
# plt.xticks(pos + wide*1.5, pos)
x= [6,12,20,7,5,5]
languages = ['Matlab','Java','Python','C','C++','Other']
plt.figure(figsize=(10,10))
explode = [0,0,0,0.1,0,0]
plt.pie(x,labels = languages, explode =explode,autopct='%1.1f%%',shadow=False)
plt.title('Circle diagram')
plt.show()