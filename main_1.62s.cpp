
#include <bits/stdc++.h>
#include <stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

using namespace std;

using UI = unsigned int;

unordered_map<UI, vector<UI>> data, data_;

int helper[280000];

UI d[280000], path[7];

UI res0[500000*3];
UI res1[500000*4];
UI res2[1000000*5];
UI res3[2000000*6];
UI res4[3000000*7];
UI *res[] = {res0, res1, res2, res3, res4};

int pd,p[5] = {0};

clock_t t[5];

static const char *infile = "/data/test_data.txt";
string outfile = "/projects/student/result.txt";

std::string to_string_(int value) {

	static const char digits[19] = {
		'9','8','7','6','5','4','3','2','1','0',
		'1','2','3','4','5','6','7','8','9'
	};
	static const char* zero = digits + 9;//zero->'0'

	char buf[24];      
	int i = value;
	char *p = buf + 24;
	*--p = '\0' ;
	do {
		int lsd = i % 10;
		i /= 10;
		*--p = zero[lsd];
	} while (i != 0);
	if (value <0)
		*--p = '-';
	return std::string(p);
}

inline void file2matrix(){
    UI u, v, _;
    while(~scanf("%u,%u,%u", &u, &v, &_)){
        data[u].push_back(v);
        data_[v].push_back(u);
    }
}

inline void cut(){
    auto iter = data.begin();
    while(iter != data.end()){
        if(data_.count(iter->first)){
            d[pd] = iter->first;
            sort(iter->second.begin(), iter->second.end());
            ++iter;
            pd ++;
        }
        else{
            data.erase(iter++);
        }
    }
}

void search_helper(UI k, UI  key, UI cnt){
    for(auto val: data_[k]){
        if(data.count(val)){
            helper[val] = key;
            if(cnt == 3) continue;
            search_helper(val, key, cnt + 1);
        }
        else continue;

    }
}

void search_circle(UI path[], int cnt){
    if(data.count(path[cnt-1])){
        for(auto& item: data[path[cnt-1]]){

            if(cnt > 3 && (helper[item] != path[0] && helper[item] != -path[0]-1)) continue;
            bool flag = false;
            if (cnt > 1){
                for(int i = 0; i < cnt-1; ++i)
                    if(path[i] == item){
                        flag = true;
                        break;
                }
            }
            if(flag) continue;
            if(cnt > 1 && helper[item] == -path[0]-1){
                path[cnt] = item;
                for(int i=0;i<=cnt;i++)
                    res[cnt-2][(cnt+1)*p[cnt-2]+i] = path[i];
                p[cnt-2]++;
            }
            if(cnt == 6) continue;

            path[cnt] = item;
            search_circle(path, cnt + 1);
        }
    }
    else return;
}

void output(string &outputFile) {

    int Num = p[0] + p[1] + p[2] + p[3] + p[4];
    FILE *fp = fopen(outputFile.c_str(), "w");
    string str = to_string(Num) + "\n";
    for (UI i = 3; i <= 7; ++i) {
        for (UI j = 0; j < i*p[i-3]; ++j) {
            if((j%i)!=(i-1))
                str += to_string_(res[i-3][j])+",";
            else
                str += to_string_(res[i-3][j])+"\n";
        }
    }
    const char *p = str.c_str();
    fwrite(p, strlen(p), 1, fp);
    fclose(fp);
}

int main(){

    t[0] = clock();
    freopen(infile, "r", stdin);

    file2matrix();
    t[1] = clock();
    cut();
    t[2] = clock();
    sort(d, d+pd);

    for(int i = 0; i < pd; i++){
        search_helper(d[i], d[i], 1);
        for(auto item: data_[d[i]]){
            if(data.count(item))
                helper[item] = -d[i]-1;
        }
        path[0] = d[i];
        search_circle(path, 1);

        data.erase(d[i]);
    }
    t[3] = clock();

    output(outfile);
    t[4] = clock();
    printf("%f\n", (double)(t[1]-t[0])/CLOCKS_PER_SEC);
    printf("%f\n", (double)(t[2]-t[1])/CLOCKS_PER_SEC);
    printf("%f\n", (double)(t[3]-t[2])/CLOCKS_PER_SEC);
    printf("%f\n", (double)(t[4]-t[3])/CLOCKS_PER_SEC);

    return 0;
}
