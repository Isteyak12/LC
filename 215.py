# 215. Kth Largest Element in an Array
def KthLelement(arr, k):
    count=1
    set_a=[]
    for i in arr:
        if i not in set_a:
            set_a.append(i)

    set_a.sort()
    print(set_a)
    for i in set_a:
        # print(i, end=" ")
        if(count==k):
            return i    
        count+=1
        
arr=[4,4,5,5,6]
print(KthLelement(arr, 2))