import java.util.LinkedHashMap;
import java.util.Scanner;

// Main Application Class
public class Main {
    public static void main(String[] args) {
        LinkedHashMap<String, Customer> customers = new LinkedHashMap<>();
        LinkedHashMap<String, Product> inventory = new LinkedHashMap<>();
        LinkedHashMap<String, Order> orders = new LinkedHashMap<>();
        Helper helper = new Helper(System.out);

        Scanner scanner = new Scanner(System.in);
        helper.processCommands(scanner, customers, inventory, orders);
    }
}
