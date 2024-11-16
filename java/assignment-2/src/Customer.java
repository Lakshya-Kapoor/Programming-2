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

    // Abstract method to get the type of customer
    public abstract String getCustomerType();

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
        return "Customer info for " + customerId + " (" + getCustomerType() + "):\nName: " + name + "\nAddress: "
                + address;
    }
}

class RegularCustomer extends Customer {
    // Constructor to initialize regular customer details
    public RegularCustomer(String customerId, String name, String email, String address) {
        super(customerId, name, email, address);
    }

    // Override method to return the type of customer as "Regular"
    @Override
    public String getCustomerType() {
        return "Regular";
    }
}

class PremiumCustomer extends Customer {
    // Constructor to initialize premium customer details
    public PremiumCustomer(String customerId, String name, String email, String address) {
        super(customerId, name, email, address);
    }

    // Override method to apply a 10% discount on the total price for premium
    // customers
    @Override
    public double getTotalPrice() {
        return super.getTotalPrice() * 0.9;
    }

    // Override method to return the type of customer as "Premium"
    @Override
    public String getCustomerType() {
        return "Premium";
    }
}