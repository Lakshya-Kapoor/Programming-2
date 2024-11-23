abstract class Customer {
    private String customerId;
    private String name;
    private String email;
    private String address;
    private ShoppingCart shoppingCart;

    // Constructor to initialize customer details and create a new shopping cart
    public Customer(String customerId, String name, String email, String address) {
        this.customerId = customerId;
        this.name = name;
        this.email = email;
        this.address = address;
        this.shoppingCart = new ShoppingCart();
    }

    // Method to get customer name
    public String getName() {
        return name;
    }

    // Method to get the address
    public String getAddress() {
        return address;
    }

    // Method to get the shopping cart of the customer
    public ShoppingCart getCart() {
        return shoppingCart;
    }

    // Method to get the total price of items in the shopping cart
    public double getTotalPrice() {
        return shoppingCart.getCartPrice();
    }

    // Override toString method to provide customer information
    @Override
    public String toString() {
        return "Customer: " + name;
    }
}

class RegularCustomer extends Customer {
    // Constructor to initialize regular customer details
    public RegularCustomer(String customerId, String name, String email, String address) {
        super(customerId, name, email, address);
    }

    @Override
    public String toString() {
        return super.toString() + " (Regular)\nAddress: " + getAddress();
    }
}

class PremiumCustomer extends Customer {
    // Constructor to initialize premium customer details
    public PremiumCustomer(String customerId, String name, String email, String address) {
        super(customerId, name, email, address);
    }

    @Override
    public double getTotalPrice() {
        return super.getTotalPrice() * 0.9;
    }

    @Override
    public String toString() {
        return super.toString() + " (Premium)\nAddress: " + getAddress();
    }
}