import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Helper {
    private PrintStream out;

    public Helper(PrintStream out) {
        this.out = out;
    }

    public void print(String message) {
        out.println(message);
    }

    public void print(Object obj) {
        out.println(obj);
    }

    private void customerExistsError(String customerId) {
        print("Error: Customer ID " + customerId + " already exists");
    }

    private void itemExistsError(String itemId) {
        print("Error: Item ID " + itemId + " already exists in inventory");
    }

    private void customerNotFoundError(String customerId) {
        print("Error: Customer ID " + customerId + " not found");
    }

    private void itemNotFoundError(String itemId) {
        print("Error: Item ID " + itemId + " not found in inventory");
    }

    public void processCommands(Scanner scanner, HashMap<String, Customer> customers,
            HashMap<String, Product> inventory) {
        while (scanner.hasNextLine()) {
            String command = scanner.nextLine();
            String[] inputs = parseCommand(command);

            switch (inputs[0]) {
                case "ADD_ELECTRONICS": {
                    String itemId = inputs[1];
                    String name = inputs[2];
                    double price = Double.parseDouble(inputs[3]);
                    int quantity = Integer.parseInt(inputs[4]);
                    int warrantyPeriod = Integer.parseInt(inputs[5]);

                    if (inventory.containsKey(itemId)) {
                        itemExistsError(itemId);
                        break;
                    }

                    if (price <= 0 || quantity <= 0 || warrantyPeriod <= 0) {
                        print("Error: Invalid value");
                        break;
                    }

                    Product item = new Electronics(itemId, name, price, quantity, warrantyPeriod);
                    inventory.put(itemId, item);
                    print("Electronics Item added: " + itemId + " " + name);
                    break;
                }

                case "ADD_FASHION": {
                    String itemId = inputs[1];
                    String name = inputs[2];
                    double price = Double.parseDouble(inputs[3]);
                    int quantity = Integer.parseInt(inputs[4]);
                    String size = inputs[5];

                    if (inventory.containsKey(itemId)) {
                        itemExistsError(itemId);
                        break;
                    }

                    Product item = new Clothing(itemId, name, price, quantity, size);
                    inventory.put(itemId, item);
                    print("Fashion Item added: " + itemId + " " + name);
                    break;
                }

                // TODO: parsing of data within quotes needs to be done
                case "ADD_REGULAR_CUSTOMER": {
                    String customerId = inputs[1];
                    String customerName = inputs[2];
                    String email = inputs[3];
                    String address = inputs[4];

                    if (customers.containsKey(customerId)) {
                        customerExistsError(customerId);
                        break;
                    }

                    Customer customer = new RegularCustomer(customerId, customerName, email, address);
                    customers.put(customerId, customer);
                    print("Regular Customer added: " + customerId + " " + customerName);
                    break;
                }

                case "ADD_PREMIUM_CUSTOMER": {
                    String customerId = inputs[1];
                    String customerName = inputs[2];
                    String email = inputs[3];
                    String address = inputs[4];
                    Customer customer = new PremiumCustomer(customerId, customerName, email, address);

                    if (customers.containsKey(customerId)) {
                        customerExistsError(customerId);
                        break;
                    }

                    customers.put(customerId, customer);
                    print("Premium Customer added: " + customerId + " " + customerName);
                    break;
                }

                // TODO: need to fix the storage of item in cart
                case "ADD_TO_CART": {
                    String customerId = inputs[1];
                    String itemId = inputs[2];
                    Customer customer = customers.get(customerId);
                    Product item = inventory.get(itemId);

                    if (customer == null) {
                        customerNotFoundError(customerId);
                    } else if (item == null) {
                        itemNotFoundError(itemId);
                    } else if (item.getQuantity() == 0) {
                        print("Item " + itemId + " is out of stock");
                    } else {
                        customer.getCart().addProduct(item);
                        item.decQuantity();
                        print("Item " + itemId + " added to " + customerId + "'s cart");
                    }
                    break;
                }

                case "VIEW_CART": {
                    String customerId = inputs[1];
                    Customer customer = customers.get(customerId);
                    if (customer != null) {
                        print("Items in cart for " + customerId + ":");
                        customer.getCart().viewCart();
                    } else {
                        customerNotFoundError(customerId);
                    }
                    break;
                }

                case "TOTAL_PRICE": {
                    String customerId = inputs[1];
                    Customer customer = customers.get(customerId);
                    if (customer != null) {
                        double total = customer.getTotalPrice();
                        print("Total Price for " + customerId + ": " + total);
                    } else {
                        customerNotFoundError(customerId);
                    }
                    break;
                }

                case "VIEW_CUSTOMER": {
                    String customerId = inputs[1];
                    Customer customer = customers.get(customerId);
                    if (customer != null) {
                        print(customer);
                    } else {
                        customerNotFoundError(customerId);
                    }
                    break;
                }

                case "EXIT":
                    scanner.close();
                    return;

                default:
                    print("Error: Invalid command format");
            }
        }
    }

    // Helper method to parse commands with quoted strings
    private String[] parseCommand(String command) {
        ArrayList<String> tokens = new ArrayList<>();
        Matcher matcher = Pattern.compile("\"([^\"]*)\"|(\\S+)").matcher(command);

        while (matcher.find()) {
            if (matcher.group(1) != null) {
                // Add quoted strings
                tokens.add(matcher.group(1));
            } else {
                // Add unquoted words
                tokens.add(matcher.group(2));
            }
        }

        return tokens.toArray(new String[0]);
    }
}
