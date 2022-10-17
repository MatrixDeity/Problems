#!/usr/bin/env bash

# LeetCode_192
# https://leetcode.com/problems/word-frequency/
# MatrixDeity, 2022.

cat ./words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -r | awk '{print $2 " " $1}'
