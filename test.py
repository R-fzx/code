import requests as rq
from urllib.parse import unquote
from bs4 import BeautifulSoup
from re import findall
import json
import pymongo
import threading

myclient = pymongo.MongoClient("mongodb://*******:27017/")
mydb = myclient['luogu']
mycol = mydb['records']

def getRecord(id):
    url = f'https://www.luogu.com.cn/record/{id}'
    headers = {
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.130 Safari/537.36',
    'cookie': '**********'
    }
    print(url)
    r = rq.get(url, headers=headers, timeout = 5)
    soup = BeautifulSoup(r.text, 'html.parser')
    res = soup.script.get_text()
    res = unquote(res.split('\"')[1])

    data = json.loads(res)
    data = data['currentData']['record']
    # print(data)

    if list(mycol.find({'id' : id})) == []:
        mycol.insert_one(data)
    else:
        print("Already")

def worker(x):
    print(f'worker {x} start')
    for i in range(x, x+100):
        try:
            getRecord(i)
        except Exception:
            pass
    print(f'worker {x} stop')

if __name__ == '__main__':
    pool = [threading.Thread(target=worker, args=[31000000 + x*100]) for x in range(100)]
    
    for x in pool:
        x.start()
    for x in pool:
        x.join()