answer = (input("Greeting: ")).lower().strip()

if answer.startswith('hello'):
    print("$0")
elif answer.startswith('h', 0 ,1):
    print("$20")
else:
    print("$100")