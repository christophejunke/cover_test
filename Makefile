all: main

.PHONY: frama-c coverity

frama-c:
	frama-c main.c \
		~/.opam/4.14.0/share/frama-c/libc/string.c \
		-eva-slevel=3 \
		-eva-partition-history=2 \
		-eva

coverity:
	cov-build --dir cov-int make
	tar czf cover_test.tgz cov-int
	sh ./push.sh

# push.sh contains the curl command as described on the website
#
# curl --form token=XXX \
#   --form XXX \
#   --form file=@cover_test.tgz \
#   --form version="1" \
#   --form description="new" \
#   https://scan.coverity.com/builds?project=XXX
