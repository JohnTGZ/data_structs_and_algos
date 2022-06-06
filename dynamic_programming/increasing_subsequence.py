#!/usr/bin/env python3

#Original problem: https://www.youtube.com/watch?v=aPQY__2H3tE&ab_channel=Reducible
#For a sequence a1, a2, ..., an, find the length of the longest increasing subsequence
#ai1, ai2, ..., ain.

# [3,1,8,2,5]. Longest subsequence is 1->2->5, of length 3
# [5,2,8,6,3,6,9,5]. Longest subsequence is 2,3,6,9, of length 4

def findLongestSubSeq(list):
    #Minimum subsequence is one
    subseq_length = [1] * len(list)
    
    
    for i in range(0, len(list)):
        prev_subsequence = []

        for j in range(0, i):
            if (list[j] < list[i]):
                prev_subsequence.append(subseq_length[j])

        if len(prev_subsequence) > 0: 
            subseq_length[i] = 1 + max(prev_subsequence)

    print(subseq_length)
    return max(subseq_length)

def main():
    list1 = [3,1,8,2,5] #Length 3
    list2 = [5,2,8,6,3,6,9,5] #Length 4
    # list3 = []
    
    print("List1")
    assert findLongestSubSeq(list1) == 3
    print("List2")
    assert findLongestSubSeq(list2) == 4


if __name__ == "__main__":
    main()