#basic python code for if else 
# about hte name == main 
# name is a var that comes by default and the  script we execurre with python script.py the var naem  is set to main 
# for script that we impoert it doest have the name set to main
if __name__ == '__main__':
    n = int(input().strip())
    if n%2!=0 :
        print("Weird")
    elif  n%2==0 and 2<=n<=5:
        print("Not Weird")
    elif n%2==0 and 6<=n<=20:
        print("Weird")
    elif n%2==0 and n>20:
        print("Not Weird")