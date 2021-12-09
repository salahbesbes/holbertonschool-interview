#!/usr/bin/python3
"""
parses the title of all hot articles,
and prints a sorted count of given
keywords (case-insensitive, delimited by spaces.
Javascript should count as javascript, but java should not).
"""
import requests


def count_words(subreddit, word_list, my_dict={}, after=''):
    """
    Results should be printed in descending order,
    by the count, and if the count is the same for separate keywords,
    they should then be sorted alphabetically (ascending, from A to Z).
    Words with no matches should be skipped and not printed.
    Words must be printed in lowercase.
    """
    url = 'https://www.reddit.com/r/{}/hot.json?after={}'
    rq = requests.get(url.
                      format(subreddit, after),
                      headers={'User-Agent': 'custom'},
                      allow_redirects=False)

    if rq and rq.status_code == 200:
        list_req = rq.json().get('data').get('children')
        for children in list_req:
            get_title = children.get('data').get('title')
            for word in word_list:
                try:
                    my_dict[word] += get_title.lower().split().count(
                        word.lower())
                except KeyError:
                    my_dict[word] = get_title.lower().split().count(
                        word.lower())

        after = rq.json().get('data').get('after')
        if (after is None):
            for key, val in sorted(my_dict.items(),
                                   key=lambda x: x[1],
                                   reverse=True):
                if (val != 0):
                    print("{}: {}".format(key, val))
            return
        return count_words(subreddit, word_list, my_dict, after)
    else:
        return
