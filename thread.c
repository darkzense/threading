#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

char word[] = "anna";
long num = 6;

void *worker1(void *arg);
void *worker2(void *arg);

int main(void)
{
    pthread_t my_thread;

    if (pthread_create(&my_thread, NULL, &worker1, word))
    {
        printf("\npthread (worker1) creation failed\n");
        abort();
    }
    if (pthread_create(&my_thread, NULL, &worker2, &num))
    {
        printf("\npthread (worker2) creation failed\n");
        abort();
    }

    printf("Waiting for threads to finish (pthread join)\n");

    if (pthread_join(my_thread, NULL))
    {
        printf("\npthread join failed\n");
        abort();
    }

    return 0;
}

void *worker1(void *arg)
{
    char *word = (char *)arg;
    sleep(2);
    printf("%s - %s\n", word, is_palindrome(word) ? "Is palindrome" : "Is not palindrome");

    return NULL;
}

void *worker2(void *arg)
{
    long *number = arg;
    sleep(4);
    printf("%d - %s\n", *number, is_perfect(*number) ? "Is a perfect number" : "Is not a perfect number");

    return NULL;
}