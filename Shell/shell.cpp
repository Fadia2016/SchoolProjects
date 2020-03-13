#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <pwd.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <errno.h>


using namespace std;

//global variables to help with the history fun.
string history[100]={""};
int trace = 0; 
int count = 0; 

// print the location (the path)
void printdir()
{
    long SizeString;
    char *buffer;
    char *p;

    SizeString = pathconf(".", _PC_PATH_MAX);

    if((buffer = (char *)malloc((size_t)SizeString))!=NULL)
        p=getcwd(buffer,(size_t)SizeString);
	
	cout << p  <<endl;
}


// for loop to save whatever in the history array (the command that user entered)
void historyfun(string str)
{
	for(int i = 0; i < 1; i++)
	history[trace]=str;
	trace++;
	
	if(trace==100)
	trace=0;
}

// to show the current directory all the time
void showPath() 
{
    long SizeString;
    char *buffer;
    char *Pointer;

    SizeString=pathconf(".", _PC_PATH_MAX);

    if((buffer = (char *)malloc((size_t)SizeString))!=NULL)
        Pointer=getcwd(buffer,(size_t)SizeString);

    struct passwd *getpwuid(uid_t uid);
    struct passwd *p;
    uid_t uid=0;
    if ((p = getpwuid(uid)) == NULL)
        perror("getpwuid() error");
    else {
        printf("%s@%s>", p->pw_name, Pointer);
    }
    free(buffer);
}


// for loop to print whatever in the history array (the command that user entered)
void printhistory()
{
	for(int i = 0; i < count; i++)
		cout<< history[i]<< endl;	
}

int main()
{
	string line="";
	pid_t pid=0;

	// to stop the shell when the user entered "exit"
	while(line!="exit")
	{
		showPath();		
		getline(cin,line); // to get the input from the user
		count++;
		historyfun(line);
		if(line == "list") // to swich the list to ls 
		line ="ls";
		char linechar[line.size()+1]; // to change the input from string to char
  		strcpy(linechar,line.c_str());
		char* argv;
		char* pargv[1000];
		 argv = strtok (linechar," "); //search for " " inside the char so we can put it in array separately
		int k = 0;
		while (argv != NULL) // get the char command to array of char 
  		{		     // for example: if you enter cd foldername, pargv[0]= cd and pargv[1] = foldername
			pargv[k] = argv;
			argv = strtok (NULL, " ");
			k++;				
		}
		pargv[k]=NULL; // to end the array where last element in the arrey should be NULL

		if(strcmp("chdir",pargv[0])==0) // to change chdir to cd so it can work both way.
			pargv[0]="cd";

		if(strcmp("cd",pargv[0])==0) // to handle changing directory only
		{
			struct passwd *pwd;
			char* show= pargv[1];
			if(show==NULL)
			{
				pwd =getpwuid(getuid());
				show=pwd->pw_dir;
			}
			
			if(show[0]=='/')
			{
				(show)=++(show);
			}
			errno=chdir(show);
			if(errno!=0)
				cout<< "error"<< endl;	
		}
		else
		{
			pid = fork(); 
			if(pid< 0) // to check if there is error which could happen in some machines
			{
				cout << "fork error" <<endl;
				exit(0);
			}
			else if(pid==0) 
			{
				execvp(pargv[0],pargv);
				if(line!="exit")
					if(line=="history")//check if the input is history 
						printhistory();
					else if(strcmp("printwd",pargv[0])==0) //check if the input is printwd
						printdir();
					else
						cout << "command not found"<< endl; // if the command not found
				exit(1);
			}
			else
			{
				wait(&pid); //waiting for the child				
			}
		}
	}//end of the while loop
   	
	return 0;
}
