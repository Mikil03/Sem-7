import asyncio
import websockets
import random
import json
import pandas as pd
data = pd.read_csv('data.csv')

async def send_data():
    async with websockets.connect('ws://3.90.223.147:8080') as websocket:
        while True:
            random_index = random.randint(0,len(data)-1)
            random_data = data.iloc[random_index]
            data_dict = {
                "id": int(random_data["id"]),
                "name": random_data["name"]
            }
     
            await websocket.send(json.dumps(data_dict))
            print(f"Sent: {data_dict}")
            await asyncio.sleep(1)

if __name__ == '__main__':
    asyncio.run(send_data())