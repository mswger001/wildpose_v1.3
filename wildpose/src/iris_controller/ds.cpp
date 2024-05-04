#include <iostream>
#include <fstream>
#include <cstring>
#include <ecal/ecal.h>

// Structure for LensAperture message
struct LensAperture {
    long long timestamp_sec;
    long long timestamp_nanosec;
    int32_t position;
};

// Class for deserializing LensAperture messages
class LensApertureDeserializer {
private:
    std::ofstream o;

public:
    LensApertureDeserializer(const std::string& out_file_name) {
        // Open CSV file to write to
        o.open(out_file_name);
        o << "timestamp_sec,timestamp_nanosec,position" << std::endl;
        std::cout << "Created CSV file for LensAperture messages" << std::endl;
    }

    void process_message(const LensAperture& msg) {
        // Write measurements to CSV
        o << msg.timestamp_sec << ","
          << msg.timestamp_nanosec << ","
          << msg.position << std::endl;
    }

    void process_all(eCAL::eh5::HDF5Meas* meas_) {
        // Process all messages from the ECAL measurement
        for (long long ID = 0; ; ++ID) {
            // Deserialize and process the message
            LensAperture msg;
            if (!deserialize_message(meas_, ID, msg)) {
                break; // No more messages
            }
            process_message(msg);
        }
    }

    bool deserialize_message(eCAL::eh5::HDF5Meas* meas_, long long ID, LensAperture& msg) {
        size_t entry_size;
        if (!meas_->GetEntryDataSize(ID, entry_size)) {
            std::cout << "Error Getting Entry Data Size" << std::endl;
            return false;
        }

        uint8_t* data = new uint8_t[entry_size];
        if (!meas_->GetEntryData(ID, data)) {
            std::cout << "Problem getting entry data: " << ID << std::endl;
            return false;
        }

        // Copy message context to LensAperture struct
        int ptr = 0;
        std::memcpy(&(msg.timestamp_sec), &data[ptr], sizeof(msg.timestamp_sec));
        ptr += sizeof(msg.timestamp_sec);

        std::memcpy(&(msg.timestamp_nanosec), &data[ptr], sizeof(msg.timestamp_nanosec));
        ptr += sizeof(msg.timestamp_nanosec);

        // Skip Header part as it's not needed for LensAperture message

        std::memcpy(&(msg.position), &data[ptr], sizeof(msg.position));
        ptr += sizeof(msg.position);

        delete[] data;
        return true;
    }
};

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_ecal_file> <lens_aperture_output_csv>" << std::endl;
        return 1;
    }

    std::string input_ecal_file = argv[1];
    std::string lens_aperture_output_csv = argv[2];

    // Initialize ECAL
    eCAL::Initialize(argc, argv, "Deserializer");

    // Create deserializer for LensAperture topic
    LensApertureDeserializer lens_aperture_deserializer(lens_aperture_output_csv);

    // Open ECAL file
    eCAL::eh5::HDF5Meas* meas = new eCAL::eh5::HDF5Meas(input_ecal_file.c_str());
    if (!meas->IsOk()) {
        std::cerr << "Failed to open ECAL file: " << input_ecal_file << std::endl;
        delete meas;
        return 1;
    }

    // Process all messages from the ECAL file
    lens_aperture_deserializer.process_all(meas);

    // Cleanup
    delete meas;

    // Cleanup ECAL
    eCAL::Finalize();

    return 0;
}
