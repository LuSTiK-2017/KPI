from functools import wraps
from time import time


def repeat_func(continue_cmd):
    def decorator(func):
        @wraps(func)
        def wrapper():
            CONTINUE_MSG = "Enter {} to continue the program or any another symbol to exit: ".format(continue_cmd)
            iscontinue = True

            while iscontinue:
                func()
                iscontinue = input(CONTINUE_MSG) == continue_cmd
        return wrapper
    return decorator


def time_measure(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
        start = time()
        result = func(*args, **kwargs)
        print("Time of exesution: {}".format(time() - start))
        return result
    return wrapper