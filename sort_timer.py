import time


def sort_numbers(numbers):
    """Sort a list of numbers using Python's built-in fast sort (Timsort)."""
    return sorted(numbers)


def main():
    # Example input list; you can replace this with any list of numbers.
    numbers = [12, 5, 20, 3, 11, 19, 8, 4, 17, 1]

    print("Input:", numbers)

    start = time.perf_counter()
    sorted_numbers = sort_numbers(numbers)
    end = time.perf_counter()

    print("Sorted:", sorted_numbers)
    print(f"Execution time: {end - start:.9f} seconds")


if __name__ == "__main__":
    main()
