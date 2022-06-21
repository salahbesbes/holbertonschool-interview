#!/usr/bin/python3
"""
count words Reddit API Model
"""
import requests


def count_words(subreddit, word_list, count={}, after=""):
    """
    queries the Reddit API, parses the title of all hot articles
    """
    if len(count) <= 0:
        for item in word_list:
            count[item] = 0

    if after is None:
        word_list = [[key, value] for key, value in count.items()]
        word_list = sorted(word_list, key=lambda x: (-x[1], x[0]))
        for k in word_list:
            if k[1]:
                print("{}: {}".format(k[0].lower(), k[1]))
        return None
    url = "https://api.reddit.com/r/{}/hot".format(subreddit)
    params = {'limit': 100, 'after': after}
    headers = {'user-agent': 'my-app/0.0.1'}
    response = requests.get(
        url,
        headers=headers,
        params=params,
        allow_redirects=False,
    )

    if response.status_code == 200:
        after = response.json().get("data").get("after")
        children = response.json().get("data").get("children")
        for child in children:
            title = child.get("data").get(
                "title")
            lower = [s.lower() for s in title.split(' ')]
            for word in word_list:
                count[word] += lower.count(word.lower())
    else:
        return None
    count_words(subreddit, word_list, count, after)
