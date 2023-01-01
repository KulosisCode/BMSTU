import matplotlib.pyplot as plt
eps = 1e-4

fig, ax1 = plt.subplots(1, 1, figsize=(10, 8))
#graphic 1
# plt.subplot(221)
ages_x = [1, 10, 100, 1000, 10000, 100000]
py_sort_y = [0, 0, 0, 0.015, 0.42, 39.6]
ax1.plot(ages_x, py_sort_y, label='mysort')

py_qsort_y = [0, 0, 0, 0, 0.016]
ax1.plot(ages_x, py_qsort_y, label='qsort')


ax1.set_xlabel('N elements')
ax1.set_ylabel('time')
ax1.set_title('Compare')
ax1.legend()
ax1.grid(True)