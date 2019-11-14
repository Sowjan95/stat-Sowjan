#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

int main(){

  struct stat buff;
  
  int i = stat("main.c", &buff);
  
  if (i < 0){
    printf("errno: %d error %s\n", errno, strerror(errno));
    printf("i: %d\n", i);
  }

  printf("\nprinting stats of: main.c\n");
  printf("file size: %lld B\n", buff.st_size);
  printf("mode: %o\n", buff.st_mode % 512);
  printf("time of last access: %s\n", ctime(&(buff.st_atime)));
 
}
