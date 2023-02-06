s = input("Do you agree?")

s = s.lower()

if s in ["y", "yes"]:
    print("Ageed.")
elif s in ["n", "no"]:
    print("Not agreed.")