#!/bin/bash

#处理url
title='
https://leetcode-cn.com/problems/consecutive-characters/
'
title=${title#*//}
title=${title#*/}
title=${title#*/}
title=${title%/*}

readonly pre_dir="document/starting/"

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
questionMes=$(python python/creat-leetcode-md.py $title $pre_dir)
echo -e "***$(date)\n$questionMes\ntitle:$title" >>logs/out.txt
cp old/main.cpp main.cpp
