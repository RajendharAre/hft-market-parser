import struct
import time
import random

def generate_binary_file():
    symbols = [b"AAPL", b"MSFT", b"GOOG", b"AMZN"]
    order_id_counter = 1000
    active_orders = {}
    
    print("Generating market_data.bin with 1,000,000 packets...")
    
    with open("market_data.bin", "wb") as f:
        for _ in range(1000000):
            msg_type = random.choice(["A", "E"]) if active_orders else "A"
            timestamp = int(time.time_ns())
            
            if msg_type == "A":
                order_id_counter += 1
                symbol = random.choice(symbols)
                shares = random.randint(10, 500) * 10
                price = random.randint(100, 1500) * 10000
                active_orders[order_id_counter] = shares
                
                data = struct.pack("<HcBQQ4sII", 32, b"A", 0, timestamp, order_id_counter, symbol, shares, price)
                f.write(data)
                
            elif msg_type == "E" and active_orders:
                order_id = random.choice(list(active_orders.keys()))
                avail_shares = active_orders[order_id]
                exec_shares = random.randint(1, max(1, avail_shares // 10)) * 10
                
                if exec_shares >= avail_shares:
                    exec_shares = avail_shares
                    del active_orders[order_id]
                else:
                    active_orders[order_id] -= exec_shares
                
                data = struct.pack("<HcBQQI", 24, b"E", 0, timestamp, order_id, exec_shares)
                f.write(data)
                
    print("Done! market_data.bin created successfully.")

if __name__ == "__main__":
    generate_binary_file()
