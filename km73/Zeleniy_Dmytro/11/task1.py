number_list = []
n = int(input("Enter number of elements of list: "))


def get_elements(n):
    """
    This function get elements for list
    Args:
       n: int number
    Returns:
       A list is the result
    Raises:
       ValueError
    """
    if n == 0:
        return number_list
    else:
        element = float(input("Enter element: "))
        number_list.append(element)
        return get_elements(n-1)

list_nums = get_elements(n)


def power_negative(nums):
    '''
        This function power negative number
        Arg:
           nums: list
        Returns:
           A correct list
        Raises:
           ValueError
    '''
    for i in nums:
        if i < 0:
            idx = nums.index(i) + 1
            nums.insert(idx, i**2)
    return nums

print(power_negative(list_nums))
