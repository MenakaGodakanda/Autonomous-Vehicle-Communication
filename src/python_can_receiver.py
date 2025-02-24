import can

def receive_can_messages():
    try:
        # Using `interface='socketcan'` (no more deprecation warnings)
        bus = can.interface.Bus(channel='vcan0', interface='socketcan')

        print("Listening for CAN messages (Press Ctrl+C to exit)...")
        
        # Infinite loop to continuously receive messages
        while True:
            message = bus.recv()  # Wait for a message

            if message:
                print(f"Received: ID=0x{message.arbitration_id:X}, Data={message.data}")

    except KeyboardInterrupt:
        print("\nReceiver stopped by user.")

    except Exception as e:
        print(f"Error: {e}")

    finally:
        # Ensures the CAN bus is properly shut down on exit
        bus.shutdown()
        print("CAN bus shutdown successfully.")

if __name__ == "__main__":
    receive_can_messages()

