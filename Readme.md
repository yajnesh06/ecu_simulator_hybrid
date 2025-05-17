

---

# ECU Simulator

An Engine Control Unit (ECU) simulator that combines high-performance C logic with Python's flexibility for CAN communication. This hybrid design allows for efficient processing of CAN messages and easy extensibility.

---

## Features

* **C-based ECU Logic**: Core ECU functionalities implemented in C for optimal performance.
* **Python CAN Interface**: Python scripts handle CAN communication, interfacing seamlessly with the C logic.
* **Modular Design**: Easily extend or modify ECU logic by updating the C code.
* **Real-time Simulation**: Processes incoming CAN messages and responds appropriately, simulating real ECU behavior.

---

## Prerequisites

* **Python 3.x**
* **C Compiler** (e.g., `gcc`)
* **Python Packages**:

  * `python-can`
  * `ctypes` (standard library)
* **CAN Interface**:

  * Ensure `can0` interface is properly configured and enabled on your system.([Stack Overflow][1])

---

## Installation

1. **Clone the Repository**

   ```bash
   git clone https://github.com/yourusername/ecu-simulator.git
   cd ecu-simulator
   ```



2. **Build the C Shared Library**

   Navigate to the `ecu/` directory and compile the C code:

   ```bash
   cd ecu
   make
   ```



This will compile `ecu_logic.c` and produce `libecu.so` in the `ecu/` folder.

3. **Install Python Dependencies**

   ```bash
   pip install python-can
   ```



---

## Usage

1. **Configure CAN Interface**

   Ensure that the `can0` interface is up and running. You can use tools like `can-utils` to set up virtual CAN interfaces if needed.

2. **Run the Simulator**

   From the project root directory:

   ```bash
   python3 main.py
   ```



The script listens on the `can0` interface, processes incoming CAN messages, and sends appropriate ECU responses.

---

## File Structure

* `ecu/ecu_logic.c` / `ecu_logic.h`: Contains core ECU logic implemented in C, including PID response generation.
* `ecu_wrapper.py`: Python wrapper using `ctypes` to call the C functions.
* `main.py`: Python script managing CAN communication, receiving messages, calling C logic, and sending responses.
* `Makefile`: Automates building the C shared library.

---

## Notes

* Modify `main.py` CAN interface settings if you use a different CAN backend or channel.
* This hybrid design allows easy extension by adding more ECU logic in C while keeping CAN communication in Python.

---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.



---

