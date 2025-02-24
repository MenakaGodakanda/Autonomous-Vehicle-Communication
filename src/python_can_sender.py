import can

def send_can_message():
    try:
        # Use `interface='socketcan'` instead of `bustype`
        bus = can.interface.Bus(channel='vcan0', interface='socketcan')

        msg = can.Message(arbitration_id=0x123, data=b'HELLOCAN', is_extended_id=False)
        bus.send(msg)

        print("Sent message on vcan0")

    except Exception as e:
        print(f"Error: {e}")

    finally:
        # Properly shutdown CAN bus
        bus.shutdown()

if __name__ == "__main__":
    send_can_message()

