abstract class Customer {
    private String customerId;
    private String name;
    private String email;
    private String address;
    private ShoppingCart shoppingCart;

    public Customer(String customerId, String name, String email, String address) {
        this.customerId = customerId;
        this.name = name;
        this.email = email;
        this.address = address;
        this.shoppingCart = new ShoppingCart();
    }

    public abstract String getCustomerType();

    public String getCustomerId() {
        return customerId;
    }

    public ShoppingCart getCart() {
        return shoppingCart;
    }

    public double getTotalPrice() {
        return shoppingCart.getCartPrice();
    }

    @Override
    public String toString() {
        return customerId + " " + name + " " + email + " " + address + " " + getCustomerType();
    }
}

class RegularCustomer extends Customer {
    public RegularCustomer(String customerId, String name, String email, String address) {
        super(customerId, name, email, address);
    }

    @Override
    public String getCustomerType() {
        return "Regular";
    }
}

class PremiumCustomer extends Customer {

    public PremiumCustomer(String customerId, String name, String email, String address) {
        super(customerId, name, email, address);
    }

    @Override
    public double getTotalPrice() {
        return super.getTotalPrice() * 0.9;
    }

    @Override
    public String getCustomerType() {
        return "Premium";
    }
}