
import requests
import json

def down_videos(url):
    headers = {
        "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/116.0.0.0 Safari/537.36"
    }

    res = requests.get(url, headers=headers).text

    dic = json.loads(res)

    for item in dic["data"]:
        video_url = item.get("playUrl", "")
        title = item.get("title")
        if video_url != "":
            video_data = requests.get(video_url, 
                                      headers=headers).content
            
            with open(f"video/{title}.mp4", "wb") as f:
                f.write(video_data)



if __name__ == '__main__':
    page_size = int(input("请输入你要爬取的页数:"))
    urls = []

    for i in range(page_size):
        url = f"https://www.ku6.com/video/feed?pageNo={i}&pageSize=40&subjectId=72"
        urls.append(url)

    for url in urls:
        down_videos(url)