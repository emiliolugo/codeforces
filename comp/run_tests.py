#!/usr/bin/env python3
import subprocess
import sys
import os

def parse_test_file(path):
    with open(path) as f:
        lines = f.read().splitlines()

    test_cases = []
    i = 0
    while i < len(lines):
        if lines[i].strip() == "InputCopy":
            input_lines = []
            i += 1
            while i < len(lines) and lines[i].strip() != "OutputCopy":
                input_lines.append(lines[i])
                i += 1
            output_lines = []
            if i < len(lines):
                i += 1  # skip "OutputCopy"
                while i < len(lines) and lines[i].strip() != "InputCopy":
                    output_lines.append(lines[i])
                    i += 1
            # strip trailing blank lines
            while input_lines and not input_lines[-1].strip():
                input_lines.pop()
            while output_lines and not output_lines[-1].strip():
                output_lines.pop()
            test_cases.append(("\n".join(input_lines), "\n".join(output_lines)))
        else:
            i += 1
    return test_cases


def compile_cpp(src, binary="/tmp/work_bin"):
    result = subprocess.run(
        ["g++", "-O2", "-std=c++17", "-o", binary, src],
        capture_output=True, text=True,
    )
    if result.returncode != 0:
        print(f"Compilation failed:\n{result.stderr}")
        sys.exit(1)
    return binary


def run_test(binary, input_str, expected, idx):
    try:
        result = subprocess.run(
            [binary], input=input_str, capture_output=True, text=True, timeout=5
        )
    except subprocess.TimeoutExpired:
        print(f"Test {idx}: TLE (timeout)")
        return

    actual = result.stdout.strip()
    expected = expected.strip()

    if actual == expected:
        print(f"Test {idx}: PASS")
    else:
        print(f"Test {idx}: FAIL")
        print(f"  Expected:\n{expected}")
        print(f"  Got:\n{actual}")


if __name__ == "__main__":
    test_file = sys.argv[1] if len(sys.argv) > 1 else "test.txt"
    src_file  = sys.argv[2] if len(sys.argv) > 2 else "work.cpp"

    if not os.path.exists(src_file):
        print(f"Source file '{src_file}' not found.")
        sys.exit(1)

    binary = compile_cpp(src_file)
    test_cases = parse_test_file(test_file)

    if not test_cases:
        print("No test cases found in", test_file)
        sys.exit(1)

    print(f"Running {len(test_cases)} test(s) against {src_file}\n")
    for i, (inp, expected) in enumerate(test_cases, 1):
        run_test(binary, inp, expected, i)
