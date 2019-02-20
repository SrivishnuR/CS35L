Read Me

Issues I ran into -
Initially when I used pthread_create, I sent in the address of the constant i as it iterated through nthreads.
However, I failed to recognize that since i is changing, what the pointer points to is modified. So this doesn't garuntee that each pthread will start at its respective location.
Another issue is that I did += start instead += nthreads initially. Each thread needs to iterate through the coloumns at the same pace, so it doesn't make sense for us to do += start.
Another issue is that the code does not work for more than 97 threads. I am unsure as to why it is as it throws a segmentation fault and this number seems very arbritrary.

Conclusions -
My implementation has improved the performance of SRT by quite a bit.

1 Thread -

real    0m43.465s
user    0m43.454s
sys     0m0.003s

2 Threads -

real    0m21.843s
user    0m43.063s
sys     0m0.004s

4 Threads -

real    0m11.272s
user    0m44.605s
sys     0m0.007s

8 Threads -

real    0m5.778s
user    0m44.856s
sys     0m0.007s

As we can see, there is a large improvement in performance with 8 threads.

The relation is approximately
user time = nthreads * real time
