// Paymmet interface
public interface Payment {
    boolean processPayment(double amount);
}

class CreditCardPayment implements Payment {

    // Process the credit card payment
    public boolean processPayment(double amount) {
        if (amount > 0) {
            return true;
        }
        return false;
    }
}

class PayPalPayment implements Payment {

    // Process the PayPal payment
    public boolean processPayment(double amount) {
        if (amount > 0) {
            return true;
        }
        return false;
    }
}