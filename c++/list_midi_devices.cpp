#include <iostream>
#include <CoreMIDI/CoreMIDI.h>
#include <CoreFoundation/CoreFoundation.h>

// Function to convert CFStringRef to std::string
std::string CFStringToString(CFStringRef cfString) {
    if (cfString == nullptr) {
        return "Unknown";
    }
    const char* cString = CFStringGetCStringPtr(cfString, kCFStringEncodingUTF8);
    if (cString) {
        return std::string(cString);
    }

    // If direct conversion failed, allocate buffer
    char buffer[256];
    if (CFStringGetCString(cfString, buffer, sizeof(buffer), kCFStringEncodingUTF8)) {
        return std::string(buffer);
    }
    return "Unknown";
}

void ListMIDIDevices() {
    ItemCount deviceCount = MIDIGetNumberOfDevices();

    if (deviceCount == 0) {
        std::cout << "No MIDI devices found." << std::endl;
        return;
    }

    std::cout << "Connected MIDI Devices:" << std::endl;

    for (ItemCount i = 0; i < deviceCount; ++i) {
        MIDIDeviceRef device = MIDIGetDevice(i);

        // Get device name
        CFStringRef deviceName;
        MIDIObjectGetStringProperty(device, kMIDIPropertyName, &deviceName);

        std::cout << "Device " << i + 1 << ": " << CFStringToString(deviceName) << std::endl;

        // Now list entities within the device
        ItemCount entityCount = MIDIDeviceGetNumberOfEntities(device);
        for (ItemCount j = 0; j < entityCount; ++j) {
            MIDIEntityRef entity = MIDIDeviceGetEntity(device, j);

            // Get entity name
            CFStringRef entityName;
            MIDIObjectGetStringProperty(entity, kMIDIPropertyName, &entityName);

            std::cout << "  Entity " << j + 1 << ": " << CFStringToString(entityName) << std::endl;
        }

        CFRelease(deviceName);
    }
}

int main() {
    std::cout << "MIDI Device List on macOS\n" << std::endl;

    ListMIDIDevices();

    return 0;
}
