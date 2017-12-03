'''
Користувач вводить послідовність натуральних чисел (мінімум два числа)
в один рядок через пробіл. Визначте значення другого за величиною елемента
у цій послідовності.
'''

MIN_INT = -100000


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


def sec_maximum(nums, idx, currMax, prevMax):
    """
    This function find second max in the list
    Args:
       nums: list
       idx: int number
       currMin: float number
       prevMax: float number
    Returns:
       A float number second max in the list
    Examples:
        >>> print(sec_maximum([1, 2, 3, 4], 0, numbers[1], numbers[0]))
        3
        >>> print(sec_maximum([1, 2, 3, "f"], 0, numbers[1], numbers[0]))
        Traceback (most recent call last):
        ...
        ValueError
    """
    if (idx == len(nums)):
        return prevMax

    if nums[idx] > currMax:
        currMax = nums[idx]
    if nums[idx] < currMax and nums[idx] > prevMax:
        prevMax = nums[idx]

    return sec_maximum(nums, idx + 1, currMax, prevMax)

numbers = input("Please, input numbers by space: ").split(" ")
count = 0

numbers = convert(numbers, count)

sec_max = sec_maximum(numbers, 0, MIN_INT, MIN_INT)

print(sec_max)
