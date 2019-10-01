n=int(input())
title = {}
author = {}
key_words = {}
publisher = {}
pub_year = {}
for _ in range(n):
    id = int(input())
    name = input()
    if title.get(name) is None:
        title[name] = []
    title[name].append(id)
    author_name = input()
    if author.get(author_name) is None:
        author[author_name] = []
    author[author_name].append(id)
    words = input().split()
    for word in words:
        if key_words.get(word) is None:
            key_words[word] = []
        key_words[word].append(id)
    pub = input()
    if publisher.get(pub) is None:
        publisher[pub]=[]
    publisher[pub].append(id)
    year = input()
    if pub_year.get(year) is None:
        pub_year[year] = []
    pub_year[year].append(id)
m = int(input())
import re
def query(dic,string):
    try:
        for each in sorted(dic[string]):
            print("{:07d}".format(each))
    except:
        print("Not Found")
for _ in range(m):
    a, b = re.split(r'[\,\:]+', input())
    b=b.strip()
    print("{}: {}".format(a,b))
    if a == '1':
        query(title,b)
    elif a == '2':
        query(author,b)
    elif a == '3':
        query(key_words,b)
    elif a== '4':
        query(publisher,b)
    else:
        query(pub_year,b)
