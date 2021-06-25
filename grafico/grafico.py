from matplotlib import pyplot as plt
import numpy as np
import math
import pandas as pd

df = pd.read_csv (r'../assets/data_size_2.csv',sep=";")
print (df)
df.drop(columns=["EXECUTION"])
df["TIME"] = df["TIME"].astype(float)
df["SIZE"] = df["SIZE"].astype(int)
dx = df.groupby(['SIZE']).max().reset_index()

print( dx )
y = []
z = []

# plt.plot( dx["SIZE"], label='n^2', linewidth=1)
# plt.plot( dx["SIZE"], dx["SIZE"], label='n', linewidth=1)
# plt.plot( dx["SIZE"], z, label='log n', linewidth=1)
print('size')
print(dx["SIZE"])
timeValues = dx["TIME"].values

for i in dx["SIZE"].values:
  i = i / (3466 * 1000)
  y.append( i*math.log(i,2))
  z.append( math.log(i,2) )

print('Y')
print(y)
# print('TIME ms')
# print(dx["TIME"] * 1000)


print(timeValues)

plt.xticks([0, 270000, 810000, 2430000, 7290000, 21870000, 60000000, 80000000])
# plt.yticks([0, 2, 4, 6, 8, 10, 12, 15, 25])
plt.yticks([0, 10, 40, 70, 100])
# plt.yticks([0, 10, 300, 400, 600, 800, 1200])


plt.plot( dx["SIZE"], y, label='n log n', scalex=False, scaley=False, linewidth=1)
plt.plot( dx["SIZE"], z, label='log n', scalex=False, scaley=False, linewidth=1)
plt.plot( dx["SIZE"], timeValues, label="nossos dados", scalex=False, scaley=False, linewidth=1)


plt.xlabel('Tamanho')
plt.ylabel('Tempo')

plt.title("Gráfico")

# Exibe a legenda e por padrão usa o label de cada plot.
plt.legend()

fig = plt.gcf()
fig.set_size_inches(18.5, 10.5)
fig.savefig('teste.png', format='png', dpi=200)

plt.show()