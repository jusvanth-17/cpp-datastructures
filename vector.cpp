// Online C++ compiler to run C++ program online
#include <iostream>
#include <list>
#include<unordered_map>
#include<queue>
using namespace std;
int main() {

    // list<int> list1={1,2,3,4,5};
    // list<int>::iterator itr = list1.begin();
    // ++itr;
    // cout<<*itr<<" ";

    // for(auto n:list1)
    
    // {
    //     cout<<n<<" ";
    // }
    
   
    // //   list<char> list2={'a','b','c','d'};

    // // for(char num1:list2)
    // // {
    // //     cout<<num1<<",";
    // // }
    // queue<string> animals;
    
    // animals.push("cat");
    // animals.push("dog");
    // cout<<"Queue:";
    // while(!animals.empty())
    // {
    //     cout<<animals.front()<<",";
    //     animals.pop();
    // }
    // cout<<animals.front();

//    unordered_map <string,int> unordered_map1 {
//    {"one",1},
//    {"two",2},
//    {"three",3}
//    };
//    unordered_map1.insert({{"four",4},{"five",5}});
//    for(const auto &it: unordered_map1)
//    {
//     string key = it.first;
//     int value= it.second;
//     cout<<key<<"-"<<value;
//     //copy
//    unordered_map <string,int> unordered_map12 (unordered_map1.begin(),unordered_map1.end());
//     for(const auto &it: unordered_map12)
//    {
//     string key = it.first;
//     int value= it.second;
//     cout<<key<<"-"<<value;
//    }
  unordered_map<int,string> student {
{111,"j"},
{222,"r"},
{333,"a"}
};
// if(student.find(333)!=student.end())
// {
//     cout<<"YES";
// }
// else{
//     cout<<"No";
// }
if(student.count(111))
{
    cout<<"Yes";
}
else
{
    cout<<"No";
}


    return 0;
}
