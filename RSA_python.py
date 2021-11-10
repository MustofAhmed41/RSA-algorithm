import math


# finds out a prime number
def is_prime(num):
    j = num
    while j >= 2:
        flag = 0
        if j % 2 == 0:
            j -= 1
            continue
        i = 3
        while i <= math.sqrt(j):
            if j % i == 0:
                flag = 1
                break
            i += 2
        if flag == 0:
            return j
        j -= 1


# maps characters to integers
def convertCharToInteger(a):
    b = ord(a)
    if 97 <= b <= 122:
        return b - 69
    elif 65 <= b <= 90:
        return b - 64
    elif b == 32:
        return 27


# converts string input to integer
def convertToCipher(input):
    val = 0
    counter = 1
    counter2 = 1
    original = input
    ret = 0
    for element in range(len(original)-1, -1, -1):
        ch = convertCharToInteger(original[element])
        if ch <= 9:
            ret += 1*counter2
            ch *= counter
            counter *= 10
        else:
            ret += 2 * counter2
            ch *= counter
            counter *= 100
        counter2 *= 10
        val += ch
    return val, ret


# euclidean algorithm
def find_GCD(a, b):
    if a == 0:
        return b
    else:
        return find_GCD(b % a, a)


# finds d
def relatively_prime(num):
    d = 4
    while d <= (num*10000000):
        val = find_GCD(num, d)
        if val == 1:
            return d
        d += 1


# finds e
def find_e(d, z):
    e = 4
    while e <= (d*10000000):
        ret = (e * d) % z
        if ret == 1:
            return e
        e += 1
    return -1


# deciphers the received ciphertext
def getText(val):
    str = ""
    if 1 <= val <= 26:
        val += 64
        # print(chr(val), end="")
        return chr(val)
    elif val == 27:
        print(' ', end="")
        return ' '
    else:
        val += 69
        # print(chr(val), end="")
        return chr(val)


# deciphers the input
def decipher_code(P, P2):
    str = ""
    while P2 > 0:
        findLastP2 = P2 % 10
        findLastP2 = math.floor(findLastP2)
        if findLastP2 == 1:
            findLastP = P % 10
            P = P / 10
            str = getText(findLastP) + str
        elif findLastP2 == 2:
            findLastP = P % 100
            P = P / 100
            str = getText(findLastP) + str
        P = math.floor(P)
        P2 = P2/10
        P2 = math.floor(P2)
    print('Plain Text : ', str)


p = is_prime(2**(int(input("Enter your value: "))))
q = is_prime(p-1)

n = p * q
z = (p-1) * (q-1)

d = relatively_prime(z)
e = find_e(d, z)
print('Prime Number p : ', p)
print('Prime Number q : ', q)
print('d : ', d)
print('n : ', n)
print('z : ', z)
print('e : ', e)

P, P2 = convertToCipher(input("Enter your text: "))

print('Plain in Number Format : ', P)
C = (P**e) % n
print('CipherText  : ', C)
C1 = (P2**e) % n
P = (C**d) % n
P3 = (C1**d) % n
print('CipherText after decryption : ', P)
# print('P2 :', P2)

decipher_code(P, P3)
