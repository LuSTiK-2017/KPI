'''
Користувач вводить послідовність натуральних чисел (мінімум одне число)
в один рядок через пробіл.
Елементи, що йдуть один за одним та рівні між собою утворюють групу.
Визначте, яка найбільша кількість однакових елементів в одній групі.
Дано: 1 2 3 4 4 4 5 6 1 1 1 1 3
Відповідь 4 – група 1 1 1 1
'''


def max_group(nums, idx, curr_count, count, el_group):
    '''
    This function find max numbers group
    Args:
        nums: list
        idx: integer
        curr_count: integer
        count: integer
        el_group: integer
    Returns:
        A list of element from max group and number of max group
    '''
    if curr_count < count:
        curr_count = count
        el_group = [str(nums[idx-1])] * curr_count
    if idx == len(nums):
        return el_group, curr_count

    if len(nums) == 1:
        return nums[idx-1], 1

    if nums[idx] == nums[idx-1]:
        count += 1
    else:
        count = 1

    return max_group(nums, idx+1, curr_count, count, el_group)

numbers = input("Please, input numbers by space: ").split(" ")

el_group, num_group = max_group(numbers, 1, 1, 1, str(numbers[0]))

print("Answer:", num_group, "- group", " ".join(el_group))
