import java.util.ArrayList;

public class ShoppingCart {
    private ArrayList<Product> products;

    public ShoppingCart() {
        products = new ArrayList<>();
    }

    public void addProduct(Product product) {
        product.decQuantity();
        products.add(product);
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
