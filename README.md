# huawei2020-Preliminary
huawei2020 Preliminary

Problem:Find all the ring(less than 300w) with the length 3-7 in a given directed graph(less than 28w edges).

Idea:DFS+Pruning. <br>
#1.cut the data with an in-degree of 0 and an out-degree of 0.<br>
#2.creat a search_helper to store the data which could arrive the target point with 3epochs.<br>
#3.DFS. cut the data not in search_helper when then length of rnig is 4.<br>
#(delete the data after searching to prevent repeat)<br>

Tset_data:https://github.com/liusen1006/2020HuaweiCodecraft-TestData <br>

I am familiar with python but not C/C++. However, the effectiveness of py is much more less than C, I had to learn C temporarily. Finally, my code cost 1.5s, ranked 117 and was eliminated（the best score is 0.1s）. The most important for the competition is the details of coding, such as IO, data structure, rather than algorithm itself.
