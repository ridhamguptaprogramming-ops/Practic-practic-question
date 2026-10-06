
# numbers = [20, 30, 40, 50, 60]

# total = 0

# for i in numbers:
#     total += i
#     print(total)

# avg = total / len(numbers)
# print("Average of the list is:", avg)

# if avg > 40:
#     print("Average is greater than 40")
# else:
#     print("Average is less than or equal to 40")

numbers = list(map(int, input("Enter numbers separated by spaces: ").split()))

total = 0

for i in numbers:
    total += i
    print(total)

avg = total / len(numbers)
print("Average of the list is:", avg)

if avg > 40:
    print("Average is greater than 40")
else:
    print("Average is less than or equal to 40")
