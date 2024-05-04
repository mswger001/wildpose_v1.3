import matplotlib.pyplot as plt
import csv
import numpy as np

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

# Function to find the index of the nearest timestamp
def find_nearest_index(array, value):
    array = np.asarray(array)
    idx = (np.abs(array - value)).argmin()
    return idx

# Read data from both CSV files
timestamps1, values1 = read_csv("brightness2_data.csv")
timestamps2, values2 = read_csv("position2_data.csv")

# Find the timestamps where there is a change in position
change_timestamps = []
for i in range(1, len(values2)):
    if values2[i] != values2[i-1]:
        change_timestamps.append(timestamps2[i])

# Calculate the average brightness between each change in position
average_brightness = []
for i in range(len(change_timestamps) - 1):
    start_index = find_nearest_index(timestamps1, change_timestamps[i])
    end_index = find_nearest_index(timestamps1, change_timestamps[i + 1])
    avg_brightness = np.mean(values1[start_index:end_index])
    average_brightness.append(avg_brightness)

# Plot the average brightness
plt.plot(change_timestamps[:-1], average_brightness, label='Average Brightness')

plt.xlabel('Timestamp')
plt.ylabel('Average Brightness')
plt.title('Average Brightness versus Time')
plt.legend()
plt.show()
