'''
Користувач вводить послідовність натуральних чисел (мінімум одне число)
в один рядок через пробіл. Визначте, скільки елементів цієї послідовності
рівні її найбільшому елементу.
'''


def convert(nums, count):
    """
    This function is converting elements of list in float type
    Args:
        nums: list
        count: integer
    Returns:
        convert list
    Examples:
        print(convert_list(["1", "2", "3", "4"], 0))
        [1, 2, 3, 4]
        print(convert_list(["f", "2", "3"], 0))
        Traceback (most recent call last):
            ...
        ValueError
    """
    if count == len(nums):
        return nums
    else:
        nums[count] = float(nums[count])
        return convert(nums, count + 1)


def maximum(nums, idx, carrMax):
    '''
    This function is find max element in the list
    Args:
        nums: list
        idx: integer
        carrMax: float
    Returns:
        Max element from list
    '''
    if idx == len(nums):
        return carrMax
    else:
        if carrMax < nums[idx]:
            carrMax = nums[idx]
        return maximum(nums, idx + 1, carrMax)


def count_max(nums, max_num, idx, count):
    '''
    This function is find numbers of max elements in the list
    Args:
        nums: list
        max_num: float
        idx: integer
        count: integer
    Returns:
        Return numbers of max elements
    '''
    if idx == len(nums):
        return count
    else:
        if nums[idx] == max_num:
            count += 1
        return count_max(nums, max_num, idx + 1, count)

str_numbers = input("Please, input numbers by space: ").split(" ")
float_numbers = convert(str_numbers, 0)
max_num = maximum(float_numbers, 0, float_numbers[0])
count = count_max(float_numbers, max_num, 0, 0)

print("Result:", str(count))
