import java.util.ArrayList;

public class ShoppingCart {
    private ArrayList<Product> products;

    public ShoppingCart() {
        products = new ArrayList<>();
    }

    public void addProduct(Product product) {
        for (int i = 0; i < products.size(); i++) {
            Product p = products.get(i);
            if (p.getProductId() == product.getProductId()) {
                p.incQuantity(); // If product already exists in cart, increase quantity
                return;
            }
        }
        Product copy = product.copy(); // If product does not exist in cart, add a new product
        copy.setQuantity(1);
        products.add(copy);
    }

    public void viewCart() {
        for (int i = 0; i < products.size(); i++) {
            System.out.println(products.get(i));
        }
    }

    public double getCartPrice() {
        int total = 0;
        for (int i = 0; i < products.size(); i++) {
            Product product = products.get(i);
            total += product.getPrice() * product.getQuantity();
        }
        return total;
    }
}
