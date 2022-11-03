#!/usr/bin/env bash

# LeetCode_195
# https://leetcode.com/problems/tenth-line/
# MatrixDeity, 2022.

tail -n+10 ./file.txt | head -n1
