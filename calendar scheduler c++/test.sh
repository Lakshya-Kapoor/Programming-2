#!/bin/bash

test_passed=true

for i in {1..6}
do
    echo "tests/test_$i.txt" | ./program > results/output.txt;
    if ! diff results/output.txt "results/result_$i.txt"; then
        echo "Test $i failed"
        test_passed=false
        break
    fi
done

if $test_passed; then
    echo "Tests passed"
fi