import requests
import os
import time
s = {}
print("请输入下载数量:")
n = int(input())
cnt = 0
for i in range(1,n+1):
    if os.path.exists(str(i)+".jpg"): # 已经存在本地图片
        with open(str(i)+".jpg","rb+") as f:
            t = f.read()
            s[t]=1 # 记录
        print(str(i)+'.jpg finish')
        continue
    response = requests.get('https://api.ixiaowai.cn/api/api.php')
    cnt = cnt + 1
    if cnt % 100 == 0: # 达到已经数量后停止一段时间
        print(str(cnt)+" pictures have been downloaded , waiting...")
        time.sleep(30)
    num = 0
    while response.content in s: # 下载到了重复图片
        response = requests.get('https://api.ixiaowai.cn/api/api.php')
        cnt = cnt + 1
        if cnt % 100 == 0:
            print(str(cnt)+" pictures have been downloaded , waiting...")
            time.sleep(30)
        num = num + 1
        print("repeat * "+str(num))
    s[response.content]=1
    with open(str(i)+".jpg","wb+") as f:
        f.write(response.content)
    print(str(i)+'.jpg finish')
