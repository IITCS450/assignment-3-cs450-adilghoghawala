Setup:
Used testlottery.c to create three processes. Each child was asssigned a different number of tickets using settickets()
-Child A: 1 ticket
-Child B: 2 tickets
-Child C: 4 tickets
Total = 7 tickets

Workload:
Each child process ran a cpu bound loop where it incremened a variable repeatedly to keep the CPU busy. Then, the process printed its progress
and called sleep(1). This was so it could give the scheduler a chance to switch to a different process. This allowed for: all process to stay
runable, competition for cpu time, and to see the effects of lottery scheduling from printed output. 

Observed Relative Shares over a sufficiently long run:
-Child A = 1/7 or 14%
-Child B = 2/7 or 28%
-Child C = 4/7 or 57%

I noticed that Child C ran the most, followed by child B, and then Child C.

Variance:
THe variance exists due to randomness. SInce the lottery scheduling is based on probability, short runs will lead to a distribution that deviates
from what is expected.
