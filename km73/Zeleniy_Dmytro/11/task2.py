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


def minimum(nums, idx, currMin):
    """
    This function find minimum in the list
    Args:
       nums: list
       idx: int number
       currMin: float number
    Returns:
       A float number minimum in the list
    Raises:
       ValueError
    """
    if (idx == len(nums)):
        return currMin

    if nums[idx] < currMin:
        currMin = nums[idx]
    return minimum(nums, idx + 1, currMin)

print(minimum(list_nums, 0, list_nums[0]))
