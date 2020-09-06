import numpy as np
import matplotlib.pyplot as plt



FILE_FORMAT_EX1 = "ExperimentOne-{},ii={}-#{}.sca"
FILE_FORMAT_EX2 = "ExperimentTwo-ii={}-#{}.sca"
FILE_FORMAT_EX3 = "ExperimentThree-ii={}-#{}.sca"
# Experiment 1
n400y = np.zeros(40)
n400x = np.array(range(10, 50))

n900y = np.zeros(40)
n900x = np.array(range(10, 50))

for N in [400, 900]:
    for ii in range(10, 50):
        average = 0
        for rep in range(0, 99):
            fileName = str(FILE_FORMAT_EX1.format(str(N), str(ii), str(rep)))
            f = open(fileName, 'r')
            file = list(f.readlines())
            
            #print(float(file[40].split(' ')[7]))
            lossRate = float(file[40].split(' ')[7])
            f.close()

            average += lossRate
        average = average/100

        if N == 400:
            n400y[(ii-10)] = average
        else:
            n900y[(ii-10)] = average
        

plt.plot(n400x, n400y, "red", n900x, n900y, "blue")
plt.title("Effect of Transmission Distance on Packet Loss Rate")
plt.ylabel("Loss Rate")
plt.xlabel("Distance (metres)")
plt.show()

# Experiment 2
y = np.zeros(8)
x = np.array(range(100, 900, 100))

for index, N in enumerate(range(100, 900, 100)):
    average = 0
    for rep in range(0, 99):
        fileName = str(FILE_FORMAT_EX2.format(str(N), str(rep)))
        f = open(fileName, 'r')
        file = list(f.readlines())
        goodPut = float(file[41].split(' ')[3])
        f.close()
        average += goodPut
    average = average/100
    y[index] = average

plt.plot(x, y)
plt.title("Effect of an Increase in User Bits on Goodput")
plt.ylabel("Goodput Rate")
plt.xlabel("Number of User Bits")
plt.show()

# Experiment 3
y = np.zeros(8)
x = np.array(range(100, 900, 100))

for index, N in enumerate(range(100, 900, 100)):
    average = 0
    for rep in range(0, 99):
        fileName = str(FILE_FORMAT_EX3.format(str(N), str(rep)))
        f = open(fileName, 'r')
        file = list(f.readlines())
        
        goodPut = float(file[41].split(' ')[3])
        f.close()
        average += goodPut
    average = average/100
    y[index] = average

plt.plot(x, y)
plt.title("Effect of an Increase in User Bits on Goodput Over Bursty Channel")
plt.ylabel("Goodput Rate")
plt.xlabel("Number of User Bits")
plt.show()