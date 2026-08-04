import socket
import struct
import random

UDP_IP = "127.0.0.1"
UDP_PORT = 9999

def generate_market_stream():
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    symbols = [b"AAPL    ", b"MSFT    ", b"GOOG    ", b"AMZN    "]
    order_id_counter = 1000
    active_orders = {}
    order_ids = []
    
    print(f"Streaming updated 8-byte binary layouts to {UDP_IP}:{UDP_PORT}...")
    
    try:
        while True:
            msg_type = random.choice(["A", "E"]) if order_ids else "A"
            
            if msg_type == "A":
                order_id_counter += 1
                symbol = random.choice(symbols)
                shares = random.randint(10, 500) * 10
                price = random.randint(100, 1500) * 10000
                
                active_orders[order_id_counter] = shares
                order_ids.append(order_id_counter)
                
                # Packed using 8s format to perfectly match 36-byte C++ OrderAddMessage structure
                data = struct.pack("<HcBQQ8sII", 36, b"A", 0, 0, order_id_counter, symbol, shares, price)
                sock.sendto(data, (UDP_IP, UDP_PORT))
                
            elif msg_type == "E" and order_ids:
                idx = random.randint(0, len(order_ids) - 1)
                order_id = order_ids[idx]
                avail_shares = active_orders[order_id]
                exec_shares = random.randint(1, max(1, avail_shares // 10)) * 10
                
                if exec_shares >= avail_shares:
                    del active_orders[order_id]
                    order_ids[idx] = order_ids[-1]
                    order_ids.pop()
                    exec_shares = avail_shares
                else:
                    active_orders[order_id] -= exec_shares
                
                data = struct.pack("<HcBQQI", 24, b"E", 0, 0, order_id, exec_shares)
                sock.sendto(data, (UDP_IP, UDP_PORT))
                
    except KeyboardInterrupt:
        print("\nStream terminated cleanly.")
    finally:
        sock.close()

if __name__ == "__main__":
    generate_market_stream()
