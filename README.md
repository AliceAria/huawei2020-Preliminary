# huawei2020-Preliminary
huawei2020 Preliminary

Problem:Find all the ring(less than 300w) with the length 3-7 in a given directed graph(less than 28w edges).<br>

Idea:DFS+Pruning. <br>
# 1.cut the data where both the in-degree and out-degree are 0.<br>
# 2.creat a search_helper to store the data which could arrive the target point with 3 epochs.<br>
# 3.DFS. cut the data not in search_helper when then length of searching path is 4.<br>
# (delete the data after searching to preve,nt repeat)<br>

Tset_data:https://github.com/liusen1006/2020HuaweiCodecraft-TestData <br>
creat_data:https://github.com/byl0561/HWcode2020-TestData <br>

I am familiar with python but not C/C++. However, the effectiveness of py is much more less than C, I had to learn C temporarily. Finally, my code cost 1.5s, ranked 54(the best score is 0.1s. It should be a NP hard problem, but actually, it doesn't for the terrible connection of data. As a result, the most important for the competition is the details of coding, such as IO, data structure, rather than algorithm itself.<br>

rematch：<br>
# 1.use multithreaded.(my code for multithreaded is a piece of sh*t, so the code is not shared)<br>
# 2.Floating-point data can only be approximate, cannot represent exact values. I was eliminated for the reason. <br>

What I gain is far from the time I spend.
