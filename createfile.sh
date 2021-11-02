#!/bin/bash

readonly title=delete-node-in-a-linked-list
readonly questionId=237

readonly pre_dir="document/"
readonly sou_dir="document/*${questionId}*"
readonly tar_dir="/home/ayanami/source/hexo/source/_posts/code/leetcode/code.md"

if [ $# != 0 ]; then
    echo >>${tar_dir}
    cat ${sou_dir} >>${tar_dir}
    exit
fi

if [ -e document/*${questionId}* ]; then
    echo "file exist"
    exit
fi

#logs
echo -e "$(date)\nquestionId:$questionId\ntitle:$title" >>logs/create-logs.txt
#markdown
python creat-leetcode-md.py $title $pre_dir
cp old/main.cpp main.cpp
