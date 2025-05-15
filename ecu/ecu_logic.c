#include "ecu_logic.h"
#include <stdlib.h>

void process_service1(const CAN_Message* request, CAN_Message* response) {
    response->arbitration_id = 0x7e8;
    response->dlc = 8;

    uint8_t mode = request->data[2];

    switch (mode) {
        case 0x00: // Supported PIDs
            response->data[0] = 0x06;
            response->data[1] = 0x41;
            response->data[2] = 0x00;
            response->data[3] = 0xBF;
            response->data[4] = 0xDF;
            response->data[5] = 0xB9;
            response->data[6] = 0x91;
            break;

        case 0x04: // Engine load
            response->data[0] = 0x03;
            response->data[1] = 0x41;
            response->data[2] = 0x04;
            response->data[3] = 0x20;
            break;

        case 0x05: // Coolant temp
            response->data[0] = 0x03;
            response->data[1] = 0x41;
            response->data[2] = 0x05;
            response->data[3] = (uint8_t)(rand() % 7 + 88 + 40);
            break;

        case 0x0C: // RPM
            response->data[0] = 0x04;
            response->data[1] = 0x41;
            response->data[2] = 0x0C;
            response->data[3] = (uint8_t)(rand() % 52 + 18);
            response->data[4] = (uint8_t)(rand() % 256);
            break;

        default: // Unknown
            response->data[0] = 0x03;
            response->data[1] = 0x7F;
            response->data[2] = mode;
            response->data[3] = 0x11; // "Service Not Supported"
            break;
    }
}
