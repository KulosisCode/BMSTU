import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cbook as cbook
eps = 1e-4

def fun(x):
    return (x**3 -4*x*x + x + 6)
def f(x):
    return (3*x*x - 8*x + 1)
def fun0(x):
    return x - x

#plt.xkcd()
# plt.figure(figsize=(20,15))
fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, figsize=(10, 8))
#graphic 1
# plt.subplot(221)
ages_x = [i for i in range(18, 56)]
py_dev_y = [20046, 17100, 20000, 24744, 30500, 37732, 41247, 45372, 
            48876, 53850, 57287, 63016, 65998, 70003, 70000, 71496, 
            75370, 83640, 84666,84392, 78254, 85000, 87038, 91991, 
            100000, 94796, 97962, 93302, 99240, 102736, 112285, 100771, 
            104708, 108423, 101407, 112542, 122870, 120000]
ax1.plot(ages_x, py_dev_y, label='Python')

js_dev_y = [16446, 16791, 18942, 21780, 25704, 29000, 34372, 37810, 
            43515, 46823, 49293, 53437, 56373, 62375, 66674, 68745, 
            68746, 74583, 79000,78508, 79996, 80403, 83820, 88833, 
            91660, 87892, 96243, 90000, 99313, 91660, 102264, 100000, 
            100000, 91660, 99240, 108000, 105000, 104000]
ax1.plot(ages_x, js_dev_y, label='JavaScript')

dev_y = [17784, 16500, 18012, 20628, 25206, 30252, 34368, 38496, 
        42000, 46752, 49320, 53200, 56000, 62316, 64928, 67317, 68748, 
        73752, 77232, 78000, 78508, 79536, 82488, 88935, 90000, 90056, 
        95000, 90000, 91633, 91660, 98150, 98964, 100000, 98988, 100000, 
        108923, 105000, 103117]
ax1.plot(ages_x, dev_y, color='#444444', linestyle='--', label='All Devs')

ax1.set_xlabel('Ages')
ax1.set_ylabel('Median Salary (USD)')
ax1.set_title('Median Salary (USD) by Age')
ax1.legend()
ax1.grid(True)



#graphic 2
t1 = np.arange(-2.0, 4.0, 0.1)
t2 = np.arange(-2.0, 4.0, 0.01)
t3 = np.array([])
t4 = np.array([0.13 ,2.53])
for i in t2 :
    if abs(fun(i)) < eps :
        t3 = np.append(t3, [i])
for i in t2 :
    if abs(f(i)) < eps:
        print(i)
        t4 = np.append(t4, [i])

# plt.subplot(222)
ax2.set_ylim(-10,10)
ax2.set_xlim(-2, 4)
ax2.plot(t1, fun0(t1), 'k--')
ax2.plot(t2, fun(t2), 'b')
ax2.plot(t3, fun(t3), 'co', label = "y(x) = 0")
ax2.plot(t4, fun(t4), 'rx', label = "Extreme point")
ax2.set_xlabel('X')
ax2.set_ylabel('Y')
ax2.set_title('Graph y = x^3 - 4x^2 + x + 6')
ax2.legend(loc = 'best')
ax2.grid(True)

#graphic 3
t = np.arange(0.01, 20.0, 0.01)
ax3.semilogx(t, np.sin(2 * np.pi * t))
ax3.set(title='Semilogx')
ax3.grid(True)

#graphic 4

price_data = (cbook.get_sample_data('goog.npz', np_load=True)['price_data']
              .view(np.recarray))
price_data = price_data[-150:]

delta1 = np.diff(price_data.adj_close) / price_data.adj_close[:-1]

volume = (15 * price_data.volume[:-2] / price_data.volume[0])**2
close = 0.003 * price_data.close[:-2] / 0.003 * price_data.open[:-2]


ax4.scatter(delta1[:-1], delta1[1:], c=close, s=volume, alpha=0.5)

ax4.set_xlabel(r'$\Delta_i$', fontsize=15)
ax4.set_ylabel(r'$\Delta_{i+1}$', fontsize=15)
ax4.set_title('Volume and percent change')
ax4.grid(True)

fig.tight_layout()

plt.show()