public abstract class Order {
    private String orderId;
    private String customerId;
    private Payment payment;

    // Constructs an Order with the specified order ID, customer ID, and payment
    // details.
    public Order(String orderId, String customerId, Payment payment) {
        this.orderId = orderId;
        this.customerId = customerId;
        this.payment = payment;
    }

    // Calculates the total price for the order based on the customer details.
    public double calculateTotal(Customer customer) {
        return customer.getTotalPrice();
    }

    // Returns the order ID.
    public String getOrderId() {
        return orderId;
    }

    // Returns the customer ID.
    public String getCustomerId() {
        return customerId;
    }

    // Returns the payment details.
    public Payment getPayment() {
        return payment;
    }

    // Processes the order for the specified customer.
    public abstract boolean processOrder(Customer customer);
}

class OnlineOrder extends Order {

    public OnlineOrder(String orderId, String customerId, Payment payment) {
        super(orderId, customerId, payment);
    }

    @Override
    public boolean processOrder(Customer customer) {
        return getPayment().processPayment(calculateTotal(customer));
    }
}

class InStoreOrder extends Order {

    public InStoreOrder(String orderId, String customerId, Payment payment) {
        super(orderId, customerId, payment);
    }

    @Override
    public boolean processOrder(Customer customer) {
        return getPayment().processPayment(calculateTotal(customer));
    }
}