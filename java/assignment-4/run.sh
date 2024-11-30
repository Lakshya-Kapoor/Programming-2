# echo "Compiling java files..."
javac -d out src/*.java
# echo "Running the program..."
cat test.txt | java -cp out Main