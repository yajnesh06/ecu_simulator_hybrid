import can
from ecu_wrapper import call_service1

def simulate():
    bus = can.interface.Bus(bustype='socketcan', channel='can0')

    try:
        while True:
            msg = bus.recv(1)
            if msg and msg.arbitration_id == 0x7df and msg.data[1] == 0x01:
                print(f"[PY] Received: {msg.data}")
                response = call_service1(msg.arbitration_id, list(msg.data))
                res_msg = can.Message(
                    arbitration_id=response.arbitration_id,
                    data=list(response.data)[:response.dlc],
                    is_extended_id=False
                )
                bus.send(res_msg)
                print(f"[PY] Sent: {res_msg}")
    except KeyboardInterrupt:
        print("Exiting.")

if __name__ == "__main__":
    simulate()
