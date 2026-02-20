#include "types.h"
#include "stat.h"
#include "user.h"

volatile int sink;

void
worker(int tickets, char *name)
{
  if(settickets(tickets) < 0){
    printf(1, "%s: settickets failed\n", name);
    exit();
  }

  for(int sec = 1; sec <= 10; sec++){
    // burn some CPU
    for(int i = 0; i < 8000000; i++)
      sink++;

    // print progress
    printf(1, "%s (tickets=%d) sec=%d\n", name, tickets, sec);

    // yield a bit
    sleep(1);
  }

  printf(1, "%s done\n", name);
  exit();
}

int
main(int argc, char *argv[])
{
  int pid;

  pid = fork();
  if(pid == 0)
    worker(1, "A");

  pid = fork();
  if(pid == 0)
    worker(2, "B");

  pid = fork();
  if(pid == 0)
    worker(4, "C");

  wait();
  wait();
  wait();

  printf(1, "parent done\n");
  exit();
}
