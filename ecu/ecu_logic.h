#ifndef ECU_LOGIC_H
#define ECU_LOGIC_H

#include <stdint.h>

typedef struct {
    uint32_t arbitration_id;
    uint8_t data[8];
    uint8_t dlc;  // Data length code (number of valid bytes in data)
} CAN_Message;

void process_service1(const CAN_Message* request, CAN_Message* response);

#endif // ECU_LOGIC_H
