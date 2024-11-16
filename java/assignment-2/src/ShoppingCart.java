import java.util.ArrayList;

public class ShoppingCart {
    private ArrayList<Product> products;

    // Constructor to initialize the products list
    public ShoppingCart() {
        products = new ArrayList<>();
    }

    // Method to add a product to the shopping cart
    public void addProduct(Product product) {
        for (int i = 0; i < products.size(); i++) {
            Product p = products.get(i);
            // If the product already exists in the cart, increase its quantity
            if (p.getProductId() == product.getProductId()) {
                p.incQuantity();
                return;
            }
        }
        // If the product does not exist in the cart, add a new product with quantity=1
        Product copy = product.copy();
        copy.setQuantity(1);
        products.add(copy);
    }

    // Method to view all products in the shopping cart
    public void viewCart() {
        for (int i = 0; i < products.size(); i++) {
            System.out.println(products.get(i));
        }
    }

    // Method to calculate the total price of all products in the cart
    public double getCartPrice() {
        int total = 0;
        for (int i = 0; i < products.size(); i++) {
            Product product = products.get(i);
            total += product.getPrice() * product.getQuantity();
        }
        return total;
    }
}
