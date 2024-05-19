import rosbag
import csv

def write_to_csv(topic, data):
    filename = topic.replace('/', '_') + '_data.csv'
    with open(filename, 'a', newline='') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(data)

# Open the ROS bag file
bag = rosbag.Bag('iris_controller/test3/test3_0.db3')

# Iterate over the messages in the bag
for topic, msg, t in bag.read_messages():
    # Process the messages as needed
    if topic == '/frame_lumisence':
        timestamp = str(msg.header.stamp.sec) + "." + str(msg.header.stamp.nanosec)
        luminance = msg.luminance
        data = [timestamp, luminance]
        write_to_csv(topic, data)
    elif topic == '/arduino_position':
        timestamp = str(msg.header.stamp.sec) + "." + str(msg.header.stamp.nanosec)
        position = msg.position
        data = [timestamp, position]
        write_to_csv(topic, data)

# Close the bag when done
bag.close()
