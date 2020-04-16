#include <time.h>
#include <stdio.h>

#define LOOP_FOR_ESTIMATION 1000000000UL

#define NSEC_PER_MSEC 1000000UL

#define NSEC_PER_SEC 1000000000UL


static inline long diff_nsec(struct timespec before, struct timespec after) {
  return (after.tv_sec * NSEC_PER_SEC + after.tv_nsec) - (before.tv_sec * NSEC_PER_SEC + before.tv_nsec);
}


static unsigned long loop_per_msec() {
  struct timespec before, after;
  clock_gettime(CLOCK_MONOTONIC, &before);
  unsigned long i;
  for (i = 0; i < LOOP_FOR_ESTIMATION; i++)
    ;
  clock_gettime(CLOCK_MONOTONIC, &after);
  return LOOP_FOR_ESTIMATION * NSEC_PER_MSEC / diff_nsec(before, after);
}

static inline void load(unsigned long nloop) {
  unsigned long i;
  for (i = 0; i < nloop; i++)
    ;
}


static void child_fn(int id, struct timespec *buf, int nrecord, unsigned long nloop_per_resol, struct timespec start) {
  int i;
  for (i = 0; i < nrecord; i++) {
    struct timespec ts;
    load(nloop_per_resol);
    clock_gettime(CLOCK_MONOTONIC, %ts);
    buf[i] = ts;
  }
  for (i = 0; i < nrecord; i++) {
    printf("%d\t%ld\t%d\n", id, diff_nsec(start, buf[i]) / NSEC_PER_MSEC, (i + 1) * 100 / nrecord);
    exit(EXIT_SUCCESS);
  }
}



static void parent_fn(int nproc) {
  int i;
  for (i = 0; i < nproc; i++)
    wait(NULL);
}

static pid_t *pids;


int main(int argc, char *argv[]) {



  if (total % resol) {}


  int nrecord / total /resol;

  struct timespec *logbuf = malloc(nrecord * sizeof(struct timespec));

  if (! logbuf) err(EXIT_FAILURE, "malloc(logbuf) failed");

  
  /* unsigned long i = loop_per_msec(); */
  /* printf("%ld\n", i); */

 
  

}
