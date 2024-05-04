import matplotlib.pyplot as plt
import csv

# Function to read data from a CSV file
def read_csv(filename):
    timestamps = []
    values = []
    with open(filename, 'r') as file:
        reader = csv.reader(file)
        for row in reader:
            timestamps.append(float(row[0]))
            values.append(float(row[1]))
    return timestamps, values

# Read data from both CSV files
timestamps1, values1 = read_csv("brightness2_data.csv")
timestamps2, values2 = read_csv("position2_data.csv")

# Plot the data
plt.plot(timestamps1, values1, label='Brightness From Frame')
plt.plot(timestamps2, values2, label='Mock Position Arduino ')

# Adding a vertical line at each change of value
for i in range(1, len(values2)):
    if values2[i] != values2[i-1]:
        plt.axvline(x=timestamps2[i], color='g', linestyle=':', )

plt.xlabel('Timestamp')
plt.ylabel('Value')
plt.title('Image Brightness & Mock Position Arduino versus Time')
plt.legend()
plt.show()
