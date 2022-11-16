#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

/* copied and modified from 4.14.0 frama-c libc */

/*@
  requires valid_path: valid_read_string(path);
  assigns \result \from indirect:path, indirect:path[0..strlen(path)],
                        indirect:mode;
  ensures \result == 0 || (\result == -1 && errno \in {EACCES, EEXIST, ELOOP, EMLINK, ENAMETOOLONG, ENOENT, ENOSPC,ENOTDIR, EROFS});
*/
extern int mkdir(const char *path, mode_t mode);

struct foo {
    char* ok;
};

int init(struct foo *f)
{
    int res = 0;
    res = mkdir("/bin/cover_test", 0611);
    if (res < 0) {
        res = -errno;
        goto out;
    }
    f->ok = strdup("o_");
    if (f->ok == NULL)
        res = -EINVAL;
out:
    return res;
}

int main(int argc, char **argv)
{
    struct foo f;
    int res = init(&f);
    if (res < 0)
        return 255;
    f.ok[1] = 'k';
    printf("%s\n", f.ok);
    free(f.ok);
    return 0;
}
