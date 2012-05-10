#include "../common.h"
#include <pthread.h>

void *thr_fn1(void *arg)
{
    printf("thread 1 returning.\n");
    return (void *) 1;
}

void *thr_fn2(void *arg)
{
    printf("thread 2 returning.\n");
    return (void *) 2 ;
}

int main(void)
{
    int err;
    pthread_t tid1, tid2;
    void *tret;

    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    // no err check

    pthread_create(&tid2, NULL, thr_fn2, NULL);
    pthread_join(tid1, &tret);
    printf("thread 1 exit code %d\n", (int)tret);

    pthread_join(tid2, &tret);
    printf("thread 2 exit code %d\n", (int)tret);

    exit(0);
}