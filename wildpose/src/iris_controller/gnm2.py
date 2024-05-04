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
plt.plot(timestamps1, values1, label='File 1')
plt.plot(timestamps2, values2, label='File 2')
plt.xlabel('Timestamp')
plt.ylabel('Value')
plt.title('Comparison of data from two files')
plt.legend()
plt.show()
