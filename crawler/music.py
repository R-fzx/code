import requests
import re
from multiprocessing import Pool
headers = {
    'Referer': 'https://music.163.com/',
    "User-Agent": "Chrome/97.0.4692.99 "
}

def get_page(url):
    res = requests.get(url, headers=headers)
    data = re.findall ( '<a title="(.*?)" href="playlist\?id=(\d+)" class="msk"></a>', res.text)
    pool = Pool(processes=4)
    pool.map(get_songs,data[:3])
    print("Done!")

def get_songs(data):
    # playlist_url = "https://music.163.com/playlist?id=%s" % data[1]
    playlist_url = "https://music.163.com/playlist?id=943659078"
    res = requests.get(playlist_url, headers=headers)
    for i in re.findall(r'<a href="/song\?id=(\d+)">(.*?)</a>', res.text):
        download_url = "http://music.163.com/song/media/outer/url?id=%s" % i[0]
        try:
            with open('music/'+i[1]+'.mp3', 'wb') as f:
                f.write(requests.get(download_url, headers=headers).content)
        except FileNotFoundError:
            pass
        except OSError:
            pass


if __name__ == '__main__':
    hot_url = "https://music.163.com/discover/playlist/?order=hot"
    get_page(hot_url)
