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

#include "code.c"
