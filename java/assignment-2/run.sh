echo "Cleaning up..."
clear
echo "Compiling files..."
javac -d out src/*.java
echo "Running program..."
java -cp out Main
