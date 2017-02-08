//Program to recursively traverse the contents of directory and print mobile numbers from text files.

#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include<fstream>
#include<iostream>

using namespace std;

  //To traverse  files in directory recursively
  void rec(char* s)
  {
     DIR* dir; //directory stream pointer which will take the path address
     struct dirent *p;
     if((dir=opendir(s))!= NULL)
        {
          while((p=readdir(dir))!= NULL)
                {
                  if(strcmp(p->d_name, ".") !=0&& strcmp(p->d_name,"..")!=0) //list all files except with '.' and ".."
                  {
                     printf("%s\n",p->d_name);
                     rec(p->d_name);
                   }
                 }
          closedir(dir);
        }
  }


  int main()
  {
      rec("c:\\");//suppose this is given directory.
      DIR* dir;
      struct dirent* p;
      if((dir=opendir("c:\\"))!=NULL)//suppose this is given directory.
      {
           while((p=readdir(dir))!=NULL)
           {
                 ifstream fin;
                 const int capacity=80;
                 char st[capacity];
                 char ch;
                 fin.open(p->d_name);//we have assumed that it is a text file and it has numbers written already.
                 while(fin) //loop terminates when fin returns zero value on reaching end of file.
                {
                      fin.getline(st,capacity);//reading the text file assuming it has data less than the capacity of st(st is a string which stores the data of file).
                      if(strlen(st)==10) //numbers which have length equal to 10 and 1st digit is greater than 6.
                      {
                         if(st[0]>54)
                         for(int i=0;i<10;i++)
                         cout<<st[i];
                         cout<<endl;
                      }
                      else
                      {
                         if(strlen(st)==13&&st[3]>54)//numbers which have +91 at the starting
                         {
                            for(int i=3;i<13;i++)
                                cout<<st[i];
                            cout<<endl;
                         }
                         else if(strlen(st)==12&&st[2]>54)//numbers which have 91 only at starting
                         {
                                for(int i=2;i<12;i++)
                                    cout<<st[i];
                                cout<<endl;
                         }
                         else
                         {
                               if(strlen(st)==11&&st[1]>54)//numbers which have 0 at starting.
                               {
                                  for(int i=1;i<11;i++)
                                      cout<<st[i];
                                  cout<<endl;
                               }
                         }
                      }

               }

         }
    }

      return 0;
  }
