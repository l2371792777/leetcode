import requests, json,re,sys

def get_problem_content(slug):
    user_agent = r'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/95.0.4638.69 Safari/537.36'
    session = requests.Session()
    url = "https://leetcode-cn.com/graphql"
    params = {'operationName': "getQuestionDetail",
              'variables': {'titleSlug': slug},
              'query': '''query getQuestionDetail($titleSlug: String!) {
            question(titleSlug: $titleSlug) {
                questionId
                difficulty
                title
                translatedTitle
                translatedContent
            }
        }'''
    }
    json_data = json.dumps(params).encode('utf8')   

    headers = {'User-Agent': user_agent, 'Connection':
               'keep-alive', 'Content-Type': 'application/json',
               'Referer': 'https://leetcode-cn.com/problems/' + slug}
    resp = session.post(url, data=json_data, headers=headers, timeout=10)
    resp.encoding = 'utf8'
    content = resp.json()

    # print(content)
    question = content['data']['question']
    print("questionId:"+question["questionId"]+"\ndifficulty:"+question['difficulty'])
    #markdown文档路径
    fileName=pre_dir+"["+question["difficulty"]+"]-"+question["questionId"]+"-"+question["title"]+".md"
    fh = open(fileName, 'w', encoding='utf-8')
    # 题目详细信息
    fh.writelines("## "+question['questionId']+"."+question["translatedTitle"]+"\n")
    fh.writelines(question['difficulty']+"  \n")
    fh.writelines(convert(question['translatedContent']))
    #题解
    fh.writelines(convert("\n### 题解:  \n* 思路  \n\n* 代码  \n```c++\n\n```"))
    fh.close()


Remove = [
    "</?p>",
    "<em>",
    "</em>",
    "<sup>",
    "</sup>",
    "<br>"
]
Replace = [
    ["<li></?code>", "<li>"],
    ["</?code></li>", "</li>"],
    ["</?code>", "\n```\n"],
    ["</?strong>", ""],
    ["<pre>", "```\n"],
    ["</pre>", "\n```"],
    ["&nbsp;", " "],
    ["&quot;", '"'],
    ["&gt;", '>'],
    ["&lt;", '<']
]

def convert(src):
    # pre内部预处理
    def remove_label_in_pre(matched):
        tmp = matched.group()
        tmp = re.sub("<[^>p]*>", "", tmp)   # 不匹配>与p
        return tmp
    src = re.sub("<pre>[\s\S]*?</pre>", remove_label_in_pre, src)   # 注意此处非贪心匹配，因为可能有多个示例

    # 可以直接删除的标签
    for curPattern in Remove:
        src = re.sub(curPattern, "", src)

    # 需要替换内容的标签
    for curPattern, curRepl in Replace:
        src = re.sub(curPattern, curRepl, src)
    return src

pre_dir=sys.argv[2]
title=sys.argv[1]
get_problem_content(title)
