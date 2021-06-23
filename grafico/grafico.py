from matplotlib import pyplot as plt
import numpy as np
import math
import pandas as pd

df = pd.read_csv (r'../assets/data_size.csv',sep=";")
print (df)

df["TIME"] = df["TIME"].astype(float)
df["SIZE"] = df["SIZE"].astype(float)
dx = df.groupby(['SIZE']).mean().reset_index()

print( dx )

y = []
z = []
for i in dx["SIZE"] :
    y.append( i*math.log(i,10) )
    z.append( math.log(i,10) )

plt.plot( dx["SIZE"], dx["SIZE"], label='n', linewidth=1)
plt.plot( dx["SIZE"], z, label='log n', linewidth=1)
plt.plot( dx["SIZE"], y, label='n log n', linewidth=1)
plt.plot( dx["SIZE"], dx["TIME"]*1000000, label="nossos dados", linewidth=1 )

plt.xlabel('Tamanho')
plt.ylabel('Tempo')

plt.title("Gráfico")

# Exibe a legenda e por padrão usa o label de cada plot.
plt.legend()

fig = plt.gcf()
fig.savefig('teste.png', format='png')

plt.show()