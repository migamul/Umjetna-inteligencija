import matplotlib.pyplot as plt
import matplotlib
import numpy as np

# r = number of rows
# c = number of columns

array = np.loadtxt("info.txt", dtype='str')
r=int(array[0])
c=int(array[1])

data = np.loadtxt("output.txt", dtype='i')

# make a figure + axes
fig, ax = plt.subplots(1, 1, tight_layout=True)

#make color map
cmap = matplotlib.colors.ListedColormap( ['white','black','yellow','red','blue','lightblue'] )
norm = matplotlib.colors.NoNorm()

# draw the grid
for x in range(r + 1):
    ax.axhline(x, lw=0.4, color='grey') # horizontal lines
for x in range(c + 1):
    ax.axvline(x, lw=0.4, color='grey') # vertical lines

# draw the boxes
ax.imshow(data, interpolation='none', cmap=cmap, extent=[0,c,0,r], norm=norm)

# turn off the axis labels
ax.axis('off')
plt.savefig('pic.png', format='PNG')
