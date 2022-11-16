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
