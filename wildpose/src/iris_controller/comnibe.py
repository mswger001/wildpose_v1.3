import csv
import numpy as np

# Function to read data from a CSV file
def read_csv(filename):
    data = []
    with open(filename, 'r') as file:
        reader = csv.reader(file)
        for row in reader:
            data.append(row)
    return data

# Function to find the index of the nearest timestamp
def find_nearest_index(array, value):
    array = np.asarray(array)
    idx = (np.abs(array - value)).argmin()
    return idx

# Read brightness data from CSV
brightness_data = read_csv("brightness2_data.csv")

# Read position data from CSV
position_data = read_csv("position2_data.csv")

# Create a new dataset combining timestamp, position, and brightness
combined_data = []
for brightness_row in brightness_data:
    timestamp = float(brightness_row[0])
    brightness = float(brightness_row[1])
    nearest_index = find_nearest_index(np.array(position_data)[:,0].astype(float), timestamp)
    position = float(position_data[nearest_index][1])  # Assuming position is in the second column
    combined_data.append([timestamp, position, brightness])

# Write combined data to a new CSV file
with open("combined_data.csv", "w", newline='') as file:
    writer = csv.writer(file)
    writer.writerow(["Timestamp", "Position", "Brightness"])
    writer.writerows(combined_data)

print("Combined dataset created successfully.")
