echo "Cleaning up..."
clear
echo "Compiling files..."
javac -d out src/*.java
echo "Running program..."
cat test.txt | java -cp out Main > out.txt
