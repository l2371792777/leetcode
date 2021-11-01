#!/bin/bash

readonly title=distribute-candies
readonly pre_dir="document/"

#logs
echo -e "$(date)\ntitle:$title" >>logs/create-logs.txt
#markdown
python creat-leetcode-md.py $title $pre_dir
cp old/main.cpp main.cpp

