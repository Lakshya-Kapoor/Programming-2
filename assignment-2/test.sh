#!/bin/bash

test_passed=true

for i in {1..8}
do
    echo "tests/test_$i.txt" | ./program > results/output.txt;
    if ! diff -w results/output.txt "results/result_$i.txt"; then
        echo "Test $i failed"
        test_passed=false
    fi
done

if $test_passed; then
    echo "Tests passed"
fi