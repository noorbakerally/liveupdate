#include <stdio.h>
#include <stdlib.h> 
#include <sys/inotify.h>
#include <unistd.h>
#include <string.h>



int main(int argc, char * argv[])
{
    int d ,i=0;  
    char path[255] ;
    struct inotify_event *event  ;
    char command[255] = "./uptex.sh  ";
    

    if(argc<=1){
      printf("Usage : %s [file] \n",argv[0]);
      printf("file : a tex file in the same directory or complete path file.\n");
      exit(1);
    }

    if(argv[1][0]!='/'){ 
      realpath(argv[1], path);
      printf("Full path : %s \n",path);
    }else{
      strcpy(path, argv[1]);
    }

    d = inotify_init(); 
    inotify_add_watch(d, path, IN_MODIFY);

    strcat(command,path);
    while(read(d,event,10000)){ 
      i++;
      printf("update %d :  %s \n",i,command);
      system(command) ;  
    }
    return(0);
}