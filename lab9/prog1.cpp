#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//вариант 200 задания 1 3 1
int qudratic_braces(vector <string>& base, vector <string>& substring_containner){
    bool flag = false;
    bool main_flag = false;
    for(string el : base){
        
        auto p1 = el.begin();
        while(p1!=el.end() && *p1!='['){
            p1++;
        }
        if(*p1=='['){
            auto p2 = p1 + 1;
            while(p2!=el.end() && *p2!=']'){
                p2++;
            }
            if(*p2==']'){
                substring_containner.push_back(string(p1+1, p2));
                flag = true;
                main_flag = true;
            }
        }
        if(!flag){
            substring_containner.push_back("");
        }
    }
    if(main_flag){
        return 1;
    }
    else{
        return 0;
    }
}

int min_operators(vector <string>& substring_containner, string& result_substring){
    int min_el = 10000000;
    string target = "+-*/";
    int counter = 0;
    int min_index = -1;
    string buf;
    buf = substring_containner[0];
    for (int i = 0; i < substring_containner.size(); i++){
        if(substring_containner[i]!=""){
            auto p1 = substring_containner[i].begin();
            while(p1!=substring_containner[i].end() && target.find(*p1)!=std::string::npos){
                p1++;
                counter++;
            }
            if(counter<min_el){
                min_el = counter;
                buf = substring_containner[i];
                min_index = i;
            }
            counter = 0;
        }
    }
    result_substring = buf;
    return (min_index);
}

int delete_latin(string& result_substring){
    bool flag = false;
    for(int i = result_substring.length()-1; i >= 0; i--){
        if((result_substring[i]>='A' && result_substring[i]<='Z') || (result_substring[i]>='a' && result_substring[i]<='z')){
            result_substring.erase(i, 1);
            flag = true;
        }
        
    }
    if(result_substring==""){
        return 0;
    }
    else if(!flag){
        return 2;
    }
    else{
        return 1;
    }
}

int main(){
    vector <string> base;
    vector <string> substring_containner;
    string buf;
    string result_substring;
    int initial_number;
    cout << "Введите число строк" << endl;
    cin >> initial_number;
    cout << "введите строки:" << endl;
    cin.ignore();
    for (int i = 0; i< initial_number; i++){
        getline(cin, buf);
        base.push_back(buf);
    }
    cout << "программа 1" << endl;
    if(!qudratic_braces(base, substring_containner)){
        cout << "не было выделено ни одной подстроки" << endl;
        return 1;
    }
    else{
        cout << "первичные подстроки:" << endl;
        for(string el : substring_containner){
            cout << el << endl;
        }
    }

    cout << "программа 2" << endl;
    int index = min_operators(substring_containner, result_substring);
    cout << result_substring << endl;

    cout << "программа 3" << endl;
    int a = delete_latin(base[index]);
    if(!a){
        cout << "все элементы удалены" << endl;
        return 0;
    }
    if(a==2){
        cout << "не было удалений" << endl;
    }
    cout << "полученная строка" << endl;
    cout << base[index];
    return 0;
}
