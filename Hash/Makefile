.PHONY:all
all:hash1 hash2
hash1:hash1.c main1.c
	gcc $^ -o $@
hash2:hash2.c main2.c 
	gcc $^ -o $@ -g
.PHONY:clean
clean:
	rm -rf hash1 hash2
