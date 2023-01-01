# import numpy as np
# import matplotlib.pyplot as plt
# import matplotlib.cbook as cbook

# # Load a numpy record array from yahoo csv data with fields date, open, close,
# # volume, adj_close from the mpl-data/example directory. The record array
# # stores the date as an np.datetime64 with a day unit ('D') in the date column.
# price_data = (cbook.get_sample_data('goog.npz', np_load=True)['price_data']
#               .view(np.recarray))
# price_data = price_data[-250:]  # get the most recent 250 trading days

# delta1 = np.diff(price_data.adj_close) / price_data.adj_close[:-1]

# # Marker size in units of points^2
# volume = (15 * price_data.volume[:-2] / price_data.volume[0])**2
# close = 0.003 * price_data.close[:-2] / 0.003 * price_data.open[:-2]

# fig, ax = plt.subplots()
# ax.scatter(delta1[:-1], delta1[1:], c=close, s=volume, alpha=0.5)

# ax.set_xlabel(r'$\Delta_i$', fontsize=15)
# ax.set_ylabel(r'$\Delta_{i+1}$', fontsize=15)
# ax.set_title('Volume and percent change')

# ax.grid(True)
# fig.tight_layout()

# plt.show()

import numpy as np
import matplotlib.pyplot as plt
import matplotlib.dates as mdates
import matplotlib.cbook as cbook

# Load a numpy structured array from yahoo csv data with fields date, open,
# close, volume, adj_close from the mpl-data/example directory.  This array
# stores the date as an np.datetime64 with a day unit ('D') in the 'date'
# column.
data = cbook.get_sample_data('goog.npz', np_load=True)['price_data']

fig, ax = plt.subplots()
ax.plot('date', 'adj_close', data=data)

# Major ticks every 6 months.
fmt_half_year = mdates.MonthLocator(interval=6)
ax.xaxis.set_major_locator(fmt_half_year)

# Minor ticks every month.
fmt_month = mdates.MonthLocator()
ax.xaxis.set_minor_locator(fmt_month)

# Text in the x axis will be displayed in 'YYYY-mm' format.
ax.xaxis.set_major_formatter(mdates.DateFormatter('%Y-%m'))

# Round to nearest years.
datemin = np.datetime64(data['date'][0], 'Y')
datemax = np.datetime64(data['date'][-1], 'Y') + np.timedelta64(1, 'Y')
ax.set_xlim(datemin, datemax)

# Format the coords message box, i.e. the numbers displayed as the cursor moves
# across the axes within the interactive GUI.
ax.format_xdata = mdates.DateFormatter('%Y-%m')
ax.format_ydata = lambda x: f'${x:.2f}'  # Format the price.
ax.grid(True)

# Rotates and right aligns the x labels, and moves the bottom of the
# axes up to make room for them.
fig.autofmt_xdate()

plt.show()