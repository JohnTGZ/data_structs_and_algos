#!/usr/bin/env python3

#Original problem: https://www.youtube.com/watch?v=aPQY__2H3tE&ab_channel=Reducible
#Given n boxes [(L1, W1, H1) (L2, W2, H2), ..., (Ln, Wn, Hn)] where box i has length Li, width Wi and height Hi,
#find the height of the tallest possible stack. Box (Li, Wi, Hi) can be on top of box (Lj, Wj, Hj)
#if Li < Lj, Wi < Wj. i.e. largest box below


# def findtallestStack(boxes):
#     #BOX AT THE TOP APPROACH

#     #Construct height array using box at current index position as the top most box
#     max_height = [0] * len(boxes)
#     for i in range(0,len(boxes)):
#         max_height[i] = boxes[i][2]

    
#     for j in range(0, len(boxes)):
#         for i in range(0, len(boxes)):
#             if i == j:
#                 continue
#             #If width and height of current box [i] is less than base box [j]
#             if boxes[i][0] < boxes[j][0] and boxes[i][1] < boxes[j][1]:
#                 max_height[i] = max(max_height[j] + boxes[i][2], max_height[i])

#     print(max_height)

#     return max(max_height)

def findtallestStack(boxes):
    #BOX AT THE BOTTOM APPROACH

    #Construct height array using box at current index position as the bottom most box
    max_height = [0] * len(boxes)
    for i in range(0,len(boxes)):
        max_height[i] = boxes[i][2]

    
    for j in range(0, len(boxes)):
        for i in range(0, len(boxes)):
            if i == j:
                continue
            #If width and height of current box [i] is less than base box [j]
            if boxes[i][0] < boxes[j][0] and boxes[i][1] < boxes[j][1]:
                max_height[j] = max_height[j] + boxes[i][2]
                print(f"max_height[{j}] = {max_height[j]} ")

    print(max_height)

    return max(max_height)

def main():
    boxes1 = [(2,3,3), (2,2,4), (4,4,2)] #Tallest height is 6
    boxes2 = [(4,5,3), (2,3,2), (3,6,2), (1,5,4), (2,4,1), (1,2,2)] #Tallest height is 7

    print("Boxes1")
    assert findtallestStack(boxes1) == 6
    print("Boxes2")
    assert findtallestStack(boxes2) == 7

if __name__ == "__main__":
    main()