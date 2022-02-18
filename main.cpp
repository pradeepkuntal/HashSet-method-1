#include<bits/stdc++.h>

using namespace std;

class HashSet 
{
    public:
      vector<list<int>>arr;
      int bucket_size;

      HashSet(int size)
      {
          bucket_size=size;
          list<int>lt;
          for(int i=0;i<bucket_size;i++)arr.push_back(lt);

      }

      int Hashkey(int key)
      {
          return key%bucket_size;
      }

      list<int>::iterator Search(int key)
      {
          int h=Hashkey(key);
          return find(arr[h].begin(),arr[h].end(),key);
      }

      void Add(int key)
      {
          int h=Hashkey(key);
          auto it=Search(key);
          if(it==arr[h].end())arr[h].push_back(key);

          return;
      }

      void Remove(int key)
      {
          int h=Hashkey(key);
          auto it=Search(key);
          if(it!=arr[h].end())arr[h].erase(it);

          return;
      }
      bool IsPresent(int key)
      {
          int h=Hashkey(key);
          auto it=Search(key);
          if(it!=arr[h].end())return 1;
          return 0;
      }

};


int main()
{
     freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cout<<"Hello world"<<endl;

    HashSet h1(15007);
    h1.Add(1);
    h1.Add(2);
    h1.Add(3);
    cout<<h1.IsPresent(1)<<endl;   

}