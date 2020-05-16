# -*- coding: utf-8 -*-
"""
Created on Tue Apr  7 11:28:37 2020

@author: asus
"""

import os
import time

def file2matrix(filename):
   
    data = {}  
    data_ = {}
    fr = open(filename,'r')
    for line in fr.readlines(): 
        listFromLine = line.split(',') 
        if int(listFromLine[0]) not in data: 
            data[int(listFromLine[0])] = []  
        if int(listFromLine[1]) not in data_: 
            data_[int(listFromLine[1])] = []
        data[int(listFromLine[0])].append(int(listFromLine[1])) 
        data_[int(listFromLine[1])].append(int(listFromLine[0])) 
    return data, data_


def cut(data, data_):
    
    flag1 = []
    for i in data:
        data[i].sort() 
        if i not in data_: 
            flag1.append(i) 
    for i in flag1:
        del(data[i])


def search(data, helper, res, path, count):
    
    if path[-1] in data: 
        for item in (data[path[-1]]): 
            if count > 1 and item in path: 
                continue        
            if count > 3:
                if item not in helper: 
                    continue
            if count > 1 and item in helper and helper[item] == 1: 
                path.append(item)
                res.append(path.copy())
                path.pop()
            if count == 6: 
                continue
            search(data, helper, res, path + [item], count+1)

def search_helper(data_, helper, k, count):
    
    if k in data_:
        for i in range(len(data_[k])):
            if data_[k][i] in data:
                helper[data_[k][i]] = count
            if count == 3:
                continue
            search_helper(data_, helper, data_[k][i], count+1)
        
t = time.time()
data, data_ = file2matrix('/data/test_data.txt')
cut(data, data_)
d = sorted(data.keys(), reverse = True) 
print(time.time()-t)
res = []
while data != {}:
    key = d[-1]
    helper = {}
    search_helper(data_, helper, key, 1)
    for item in data_[key]:
        if item in data:
            helper[item] = 1
    search(data, helper, res, [key], 1)
    del(data[key])
    del(d[-1])
res.sort(key = lambda x:len(x))


path = '/projects/student'
if not os.path.exists(path):
    os.makedirs(path)
f = open('/projects/student/result.txt', mode = 'w')
print(len(res), file = f)
for i in range(0,len(res)):
    print("{}".format(','.join(map(repr,res[i]))), file = f)
    #print(",".join(str(i) for i in res[i]), file = f)
    #np.savetxt('./data/test_data.txt', res, delimiter=',')
f.close()
print(time.time()-t)


#fr = open('/data/result.txt', 'r')
#returnMat = []        #prepare matrix to return
#for line in fr.readlines():
#    listFromLine = line.split(',')
#    for i in range(len(listFromLine)):
#        listFromLine[i] = int(listFromLine[i])
#    returnMat.append(listFromLine)
#returnMat.pop(0)
#
#if returnMat == res:
#    print(1)
#else:
#    print(0)
#for i in range(len(res)):
#    if res[i] != returnMat[i]:
#        print(i)
#        break
