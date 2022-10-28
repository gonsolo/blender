import matplotlib.pyplot as plt
import csv
  
x = []
y = []
time = 0

with open('bla.csv','r') as csvfile:
    plots = csv.reader(csvfile, delimiter = ' ')

    for row in plots:
        x.append(time)
        time += 1
        y.append(int(row[0]))
  
plt.bar(x, y, color = 'g', width = 0.72)
plt.xlabel('closure_split                                       master')
plt.ylabel('GPU Memory (MiB)')
plt.title('Blender GPU memory')
ax = plt.gca()
ax.set_ylim([5400, 5700])
plt.legend()
plt.show()

