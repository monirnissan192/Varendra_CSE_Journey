from time import perf_counter_ns
from typing import Iterable, TypeVar


Number = TypeVar("Number")


def sort_numbers(numbers: Iterable[Number]) -> list[Number]:
    """Sort a list of numbers using Python's built-in fast sort (Timsort)."""
    return sorted(numbers)


def benchmark_sort(numbers: list[Number], runs: int = 10_000) -> tuple[list[Number], float]:
    """Return the sorted values and average sorting time over several runs."""
    if runs < 1:
        raise ValueError("runs must be at least 1")

    start = perf_counter_ns()
    for _ in range(runs):
        sorted_numbers = sort_numbers(numbers)
    elapsed_ns = perf_counter_ns() - start

    return sorted_numbers, elapsed_ns / runs / 1_000_000_000


def main():
    # Example input list; you can replace this with any list of numbers.
    numbers = [12, 5, 20, 3, 11, 19, 8, 4, 17, 1]

    print("Input:", numbers)

    sorted_numbers, average_time = benchmark_sort(numbers)

    print("Sorted:", sorted_numbers)
    print(f"Average execution time: {average_time:.9f} seconds")


if __name__ == "__main__":
    main()
