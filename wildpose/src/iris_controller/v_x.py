import matplotlib.pyplot as plt
import csv

# Function to read data from a CSV file
def read_csv(filename):
    data = []
    with open(filename, 'r') as file:
        reader = csv.reader(file)
        next(reader)  # Skip the header
        for row in reader:
            data.append(row)
    return data

# Read combined data from CSV
combined_data = read_csv("combined_data.csv")

# Extract position and brightness data
positions = [int(float(row[1])) for row in combined_data]
brightness = [(float(row[2])) for row in combined_data]

# Plot initial and end positions with different colors for increases and decreases
x_values = []
y_values = []

# Find the index where position changes occur
change_indices = []
for i in range(1, len(positions)):
    if positions[i] != positions[i - 1]:
        change_indices.append(i)

# Plot initial and end positions with different colors for increases and decreases
for i in range(len(change_indices) - 1):
    start_index = change_indices[i]
    end_index = change_indices[i + 1]

    if positions[start_index] < positions[end_index]:
        color = 'green'  # Increase in position
    else:
        color = 'blue'  # Decrease in position

    plt.scatter(positions[end_index - 1], brightness[end_index - 1], color=color)

    x_values.append(positions[end_index - 1])
    y_values.append(brightness[end_index - 1])
# Set integer values on x-axis
plt.xticks(range(min(x_values), max(x_values) + 1))

plt.xlabel('Position')
plt.ylabel('Brightness')
plt.title('Brightness vs Position')
plt.grid(False)
plt.show()
