import subprocess
import os
import pytest

INPUT = """\
5
6
12 7 9 4 18 5
4
3 6 2 8
7
1 10 15 20 3 6 9
5
11 14 21 2 5
3
6 6 6
"""

EXPECTED_OUTPUT = """\
12 18 4 7 5 9
2 8 3 6
6 10 20 1 15 3 9
21 5 11 2 14
6 6 6
"""

DIR = os.path.dirname(os.path.abspath(__file__))


def count_subarrays_div6(arr):
    # product divisible by 6 iff subarray contains a multiple of 2 AND a multiple of 3
    count = 0
    for i in range(len(arr)):
        has2 = False
        has3 = False
        for j in range(i, len(arr)):
            if arr[j] % 2 == 0:
                has2 = True
            if arr[j] % 3 == 0:
                has3 = True
            if has2 and has3:
                count += 1
    return count


def get_actual_output():
    bin_path = os.path.join(DIR, "C_Snowfall.bin")
    if not os.path.exists(bin_path):
        cpp_path = os.path.join(DIR, "C_Snowfall.cpp")
        subprocess.run(["g++", "-O2", "-o", bin_path, cpp_path], check=True)
    result = subprocess.run(
        [bin_path],
        input=INPUT,
        capture_output=True,
        text=True,
        timeout=10,
    )
    assert result.returncode == 0, f"Binary exited with code {result.returncode}\n{result.stderr}"
    return result.stdout


def parse_lines(output: str) -> list[list[int]]:
    return [
        [int(x) for x in line.split()]
        for line in output.strip().splitlines()
        if line.strip()
    ]


@pytest.fixture(scope="module")
def case_pairs():
    actual = parse_lines(get_actual_output())
    expected = parse_lines(EXPECTED_OUTPUT)
    return list(zip(actual, expected))


def test_case_count(case_pairs):
    expected_lines = parse_lines(EXPECTED_OUTPUT)
    assert len(case_pairs) == len(expected_lines), (
        f"Got {len(case_pairs)} output lines, expected {len(expected_lines)}"
    )


@pytest.mark.parametrize("case_idx", range(5))
def test_subarray_div6_count(case_idx, case_pairs):
    actual_arr, expected_arr = case_pairs[case_idx]
    actual_count = count_subarrays_div6(actual_arr)
    expected_count = count_subarrays_div6(expected_arr)
    assert actual_count == expected_count, (
        f"Case {case_idx + 1}: your output {actual_arr} has {actual_count} subarrays "
        f"divisible by 6, but expected output {expected_arr} has {expected_count}"
    )
