#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include <sys/stat.h>

struct foo {
    char* uid;
};

int fill(struct foo *f)
{
    int res = mkdir("/bin/file", 0611);
    if (res < 0)
        return -errno;
    f->uid = strdup("ok");
    if (f->uid == NULL)
        return -EINVAL;
    return 0;
}

int main(int argc, char **argv)
{
    struct foo f = {0};
    int res = fill(&f);
    if (res < 0)
        return 255;
    printf("%s\n", f.uid);
    free(f.uid);
    return 0;
}
