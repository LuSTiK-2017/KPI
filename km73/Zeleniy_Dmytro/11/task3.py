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


def reverse_list(nums, idx):
    '''
        This function reverse list
        Args:
           nums: list
           idx: int number
        Returns:
           A reverse list
        Raises:
           ValueError
    '''
    rev = []
    if (idx == len(nums)):
        return []
    rev = reverse_list(nums, idx + 1)
    rev.append(nums[idx])
    return rev

list_nums = reverse_list(list_nums, 0)
print(list_nums)
