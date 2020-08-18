def sl(array):
    for i in range(len(array)):
        for j in range(i+1):
            if array[i] < array[j]:
                array[i],array[j] = array[j],array[i] #冒泡排序 从小到大#
    return
def ls(array):
    for i in range(len(array)):
        for j in range(i+1):
            if array[i] > array[j]:
                array[i],array[j] = array[j],array[i] #冒泡排序 从大到小#
    return

a = [0]*10;
print ('Input 10 numbers');
for k in range(len(a)):
    a[k] = int(input());
print('small to large or not,1/0');
b = int(input());
if b==1:sl(a);print (a);
else:
        if b==0:ls(a);print (a);
        else:
                print('error!');

