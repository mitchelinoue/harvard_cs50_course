class Jar:
    def __init__(self, capacity=12):
        if capacity < 0:
            raise ValueError("Capacity error")

        self.capacity = capacity
        self.size = 0

    def __str__(self):
        cookies = self.size * "🍪"
        return cookies


    def deposit(self, n):
        self.size += n


    def withdraw(self, n):
        self.size -= n

    @property
    def capacity(self):
        return self._capacity

    @capacity.setter
    def capacity(self, capacity):
        if capacity < 0:
            raise ValueError("Invalid capacity")
        self._capacity = capacity

    @property
    def size(self):
       return self._size

    @size.setter
    def size(self, size):
        self._size = size

def main():
    jar = Jar()
    print(str(jar.capacity))
    print(str(jar))
    jar.deposit(5)
    print(str(jar))
    jar.withdraw(1)
    print(str(jar))





if __name__ == "__main__":
    main()
