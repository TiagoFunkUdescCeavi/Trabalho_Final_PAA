from matplotlib import pyplot as plt
import numpy as np
import math
import pandas as pd

df = pd.read_csv (r'./assets/data.csv')
print (df)

x = np.linspace(1, 50, num=100)
y = []
for i in x :
    y.append( i*math.log(i,2) )

plt.plot(x, y, label='n log n', linewidth=1)

plt.xlabel('x label')
plt.ylabel('y label')

plt.title("Gráfico")

# Exibe a legenda e por padrão usa o label de cada plot.
plt.legend()

# Configurações do texto
plt.text(1.00, 1.0, "Cruzamento das Linhas", fontsize=8, horizontalalignment='right')

plt.show()