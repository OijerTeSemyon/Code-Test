#一目了然，无需注释#
import random
a = random.randint(0,100);
print('猜数字0-100');
b = 100;
while a!=b:
    b = int(input('input: '));
    if a>b: print('小了')
    else:
        if a<b:print('大了')
        else: print('对了') 
      
    
