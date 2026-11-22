#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit limit;

    getrlimit(RLIMIT_STACK, &limit);
    printf("Maximum Stack Size: %ld\n", (long)limit.rlim_cur);

    getrlimit(RLIMIT_NPROC, &limit);
    printf("Maximum Number of Processes: %ld\n", (long)limit.rlim_cur);

    getrlimit(RLIMIT_NOFILE, &limit);
    printf("Maximum Number of File Descriptors: %ld\n", (long)limit.rlim_cur);

    return 0;
}
