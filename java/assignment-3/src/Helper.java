import java.io.PrintStream;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.Map;
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

    public void processCommands(Scanner scanner, LinkedHashMap<String, Customer> customers,
            LinkedHashMap<String, Product> inventory, LinkedHashMap<String, Order> orders) {

        int customerCount = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < customerCount; i++) {
            String command = scanner.nextLine();
            String[] inputs = parseCommand(command);

            String customerId = inputs[0];
            String customerName = inputs[1];
            String email = inputs[2];
            String address = inputs[3];
            String type = inputs[4];

            Customer newCustomer = null;
            switch (type) {
                case "Regular":
                    newCustomer = new RegularCustomer(customerId, customerName, email, address);
                    customers.put(customerId, newCustomer);
                    break;

                case "Premium":
                    newCustomer = new PremiumCustomer(customerId, customerName, email, address);
                    customers.put(customerId, newCustomer);
                    break;

                default:
                    break;
            }

        }

        int productCount = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < productCount; i++) {
            String command = scanner.nextLine();
            String[] inputs = parseCommand(command);

            String productId = inputs[0];
            String productType = inputs[1];
            String productName = inputs[2];
            double price = Double.parseDouble(inputs[3]);
            int quantity = Integer.parseInt(inputs[4]);

            Product newProduct = null;
            switch (productType) {
                case "Electronics":
                    int warranty = Integer.parseInt(inputs[5]);
                    newProduct = new Electronics(productId, productName, price, quantity, warranty);
                    inventory.put(productId, newProduct);
                    break;

                case "Fashion":
                    String size = inputs[5];
                    newProduct = new Clothing(productId, productName, price, quantity, size);
                    inventory.put(productId, newProduct);
                    break;

                default:
                    break;
            }

        }

        int cartAddCount = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < cartAddCount; i++) {
            String command = scanner.nextLine();
            String[] inputs = parseCommand(command);

            String customerId = inputs[0];
            String productId = inputs[1];
            int quantity = Integer.parseInt(inputs[2]);

            Customer customer = customers.get(customerId);
            Product product = inventory.get(productId);

            customer.getCart().addProduct(product, quantity);
        }

        int orderCount = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < orderCount; i++) {
            String command = scanner.nextLine();
            String[] inputs = parseCommand(command);

            String orderId = inputs[0];
            String customerId = inputs[1];
            String orderType = inputs[2];
            String paymentType = inputs[3];

            Payment payment = null;
            if (paymentType.equals("CreditCard")) {
                payment = new CreditCardPayment();
            } else if (paymentType.equals("PayPal")) {
                payment = new PayPalPayment();
            } else {
                out.println(paymentType);
                continue;
            }

            Order newOrder = null;
            switch (orderType) {
                case "Online":
                    newOrder = new OnlineOrder(orderId, customerId, payment);
                    break;

                case "InStore":
                    newOrder = new InStoreOrder(orderId, customerId, payment);
                    break;

                default:
                    break;
            }

            if (newOrder != null) {
                orders.put(orderId, newOrder);
            } else {
                // Print error message
            }
        }

        for (Map.Entry<String, Customer> entry : customers.entrySet()) {
            Customer customer = entry.getValue();
            out.println(customer);
            customer.getCart().viewCart();

            if (customer instanceof RegularCustomer) {
                out.println("Total: " + customer.getTotalPrice() + "0");
            } else {
                out.println("Total (after 10% discount): " + customer.getTotalPrice() + "0");
            }
        }

        for (Map.Entry<String, Order> entry : orders.entrySet()) {
            Order order = entry.getValue();
            String orderId = order.getOrderId();
            String customerId = order.getCustomerId();
            Payment payment = order.getPayment();

            Customer customer = customers.get(customerId);
            out.println("Processing Order " + orderId + " for " + customer.getName());
            if (payment instanceof PayPalPayment) {
                out.println("Payment Method: " + "PayPal");
            } else {
                out.println("Payment Method: " + "Credit Card");
            }
            if (order.processOrder(customer)) {
                out.println("Payment Status: Successful");
            } else {
                out.println("Payment Status: Failed");
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
