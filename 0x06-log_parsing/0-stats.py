#!/usr/bin/python3
""" regex module used """
import re
from sys import stdin, stdout


# this regex is splited into groups that we can access later on
# the status code is at groupe 4 and the size is at 5
regex_list = [r'(^(?:[0-9]{1,3}\.){3}[0-9]{1,3}) - ',  # 255.255.255.255
              r'(\[\d{4}\-\d{2}\-\d{2} \d{2}:\d{2}:\d{2}\.\d+\] )',  # date
              r'(\"GET /projects/260 HTTP/1\.1\" )',  # litral
              r'(\d{3}) ',  # 3 digit nb
              r'(\d+)']  # any number
#  r is important to avoid warning of pep8
regex = r''.join(regex_list)


def update_data(newData, oldData):
    """  update the old dict with data of one line """
    try:
        # cast data in newdata dict
        status_line = int(newData["status_code"])
        line_size = int(newData["file_size"])

        # update the size
        oldData["file_size"] += line_size
        # if the status code is in the lis update the count
        if str(status_line) in oldData["status_code"].keys():
            oldData["status_code"][str(status_line)] += 1

    except Exception:
        pass


def print_some_information(data):
    """  print a custum dict """
    print("File size: {}".format(data["file_size"]))
    # print the count of each status in the dict in asceding way
    for status, count in sorted(data["status_code"].items(),
                                key=lambda x: x[0]):
        print("{}: {}".format(status, count))


if __name__ == "__main__":

    try:

        line_number = 0
        data_to_print = {
            "file_size": 0,
            "status_code": {"200": 0,
                            "301": 0,
                            "400": 0,
                            "401": 0,
                            "403": 0,
                            "404": 0,
                            "405": 0,
                            "500": 0}
        }

        # read all stdin and save thel to a list of lines
        for line in stdin:
            try:
                line_number += 1
                line_size = 0
                line_status_code = 0
                words = line.split()
                line_size += int(words[-1])
                line_status_code = int(words[-2])

                update_data({"file_size": line_size,
                            "status_code": line_status_code}, data_to_print)
                # every 10 lines print
                if line_number % 10 == 0:
                    print_some_information(data_to_print)
            except Exception:
                pass

        # after looping all file print the last few line ( < 10)
        if line_number % 10 != 0:
            print_some_information(data_to_print)
    finally:
        print_some_information(data_to_print)
