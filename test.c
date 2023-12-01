#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <errno.h>

/*
 * SYS_desired_name
 */
#define SYS_mert_keskin 335 /*it should be same as the number in the syscall table*/

int main(int argc, char **argv)
{
if (argc <= 1) {
    printf("Must provide a string to give to system call.\n");
    return -1;
  }
  char *arg = argv[1];
  printf("Making system call with \"%.50s\".\n", arg);
  long res = syscall(SYS_mert_keskin, arg); /*in my case it is same as syscall(335,arg)*/
  if (res == -1)
    fprintf(stderr, "mert_keskin failed, errno = %d\n", errno);
  else
    printf("System call mert_keskin returned %ld.\n", res);
  return res;
}

