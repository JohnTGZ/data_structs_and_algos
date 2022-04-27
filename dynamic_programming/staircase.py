from itertools import combinations


def solution(n):
    l = [] 

    #List l contains all the possible steps that can be used
    for i in range(1,n):
        l.append(i)

    #sol continas all the possible combinations of intergers of list l
    sol = []
    
    #How many possible ways can you combine steps to produce a sum
    for k in range(2,len(l)+1):
        #return all possible subsets with length k
        for m in combinations(l,k):
            sol.append(m)
    
    print("sol ", sol)

    final = []
    
    #Iterate through sol, and only append combinations with sum == height
    for z in (sol):
        if sum(z) == n :
            final.append(z)
    
    print("Final ", final)

    steps = len(final)
    
    return (steps)


n= 5
print("no of possible combinations: ", solution(n))