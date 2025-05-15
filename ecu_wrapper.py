import ctypes
from ctypes import Structure, c_uint32, c_uint8

class CANMessage(Structure):
    _fields_ = [
        ("arbitration_id", c_uint32),
        ("data", c_uint8 * 8),
        ("dlc", c_uint8),
    ]

lib = ctypes.CDLL('./ecu/libecu.so')
lib.process_service1.argtypes = [ctypes.POINTER(CANMessage), ctypes.POINTER(CANMessage)]

def call_service1(arbitration_id, data):
    req = CANMessage(arbitration_id=arbitration_id, data=(c_uint8 * 8)(*data), dlc=8)
    res = CANMessage()
    lib.process_service1(ctypes.byref(req), ctypes.byref(res))
    return res
