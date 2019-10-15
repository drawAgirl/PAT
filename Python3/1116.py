n=int(input())
prime = [False for i in range(n+1)]
reward = {}
for i in range(2,n+1):
    if prime[i] == False:
        for j in range(2*i,n+1,i):
            prime[j] = True
for i in range(1,n+1):
    id = int(input())
    if i == 1:
        reward[id] = 1
    elif prime[i] == False:
        reward[id] = 2
    else:
        reward[id] = 3
n = int(input())
for _ in range(n):
    query = int(input())
    print("%04d: "%query,end='')
    if reward.get(query) is None:
        print("Are you kidding?")
    else:
        if reward[query] == 1:
            reward[query] = 4
            print("Mystery Award")
        elif reward[query] == 2:
            reward[query] = 4
            print("Minion")
        elif reward[query] == 3:
            reward[query] = 4
            print("Chocolate")
        else:
            print("Checked")
            