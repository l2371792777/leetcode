#!/bin/bash

readonly title=que-shi-de-shu-zi-lcof
readonly questionId=10086

readonly pre_dir="document/starting/"
readonly sou_dir="document/*${questionId}*"

if [[ -e document/starting/*${questionId}* ]] || [[ -e document/finish/*${questionId}* ]]; then
    echo "file exist"
    exit
fi

#logs
logline=$(cat logs/out.txt | wc -l)
#大于300行新建logs文件
if [ $logline -gt 300 ]; then
    cd logs/
    outnums=$(ls -l | grep "out*" | wc -l)
    mv out.txt out-${outnums}.txt
    echo -e "***$(date)\nnew log" >out.txt
    cd -
fi

#markdown
questionIdid=`python creat-leetcode-md.py $title $pre_dir`
echo -e "***$(date)\nquestionId:$questionIdid\ntitle:$title" >>logs/out.txt
cp old/main.cpp main.cpp
