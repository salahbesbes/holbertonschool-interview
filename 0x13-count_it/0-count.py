#!/usr/bin/python3
""" Count Words in reddit's hot articles section """

import requests
from collections import OrderedDict


def count_words(subreddit, word_list, word_count={}, after=''):
    """ Recursive function that queries the Reddit API """
    if len(word_count) <= 0:
        for word in word_list:
            word_count[word.lower()] = 0

    if after is None:
        sorted_word_count = OrderedDict(word_count.items())
        for key, value in sorted_word_count.items():
            if value > 0:
                print("{}: {}".format(key, value))
        return None

    url = 'https://api.reddit.com/r/{}/hot'.format(subreddit)
    headers = {'user-agent': 'counting-app'}
    params = {'limit': 100, 'after': after}
    response = requests.get(url, headers=headers,
                            params=params, allow_redirects=False)

    if response.status_code == 200:
        after = response.json().get('data').get('after')
        children = response.json().get('data').get('children')
        for child in children:
            lowercase_title = child.get(
                "data").get('title').lower().split(' ')
            for word in word_list:
                word_count[word] += lowercase_title.count(word)
        count_words(subreddit, word_list, word_count, after)
    else:
        return None
