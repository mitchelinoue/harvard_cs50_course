people = {
    "Carter": "(11) 1234-5678",
    "David": "(17) 1234-5678"
}
name = input("Name: ")
if name in people:
    number = people[name]
    print(f"Number: {number}")