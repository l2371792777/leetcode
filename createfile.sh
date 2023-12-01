#!/bin/zsh

#处理url
url='https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/'
title=${url#*//}
title=${title#*/}
title=${title#*/}
title=${title%/*}

readonly pre_dir="document/starting/"

#markdown
questionMes=$(python python/creat-leetcode-md.py $title $pre_dir)

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


#备份
cp main.cpp main.cpp.back
cp old/main.cpp main.cpp
sed -i '4i\'" * title:$title" main.cpp

echo -e "***    $(date)\n$questionMes url:$url" >>logs/out.txt