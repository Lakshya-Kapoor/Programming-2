class Product {
    private String productId;
    private String name;
    private double price;
    private int quantity;

    // constructor
    public Product(String productId, String name, double price, int quantity) {
        this.productId = productId;
        this.name = name;
        this.price = price;
        this.quantity = quantity;
    }

    // copy constructor
    public Product(Product other) {
        this(other.productId, other.name, other.price, other.quantity);
    }

    // returns copy of the object
    public Product copy() {
        return new Product(this);
    }

    // getters
    public String getProductId() {
        return productId;
    }

    public double getPrice() {
        return price;
    }

    public int getQuantity() {
        return quantity;
    }

    // set quantity to a specific value
    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    @Override
    public String toString() {
        return productId + " " + name + " " + price + "0 Quantity: " + quantity;
    }
}

class Electronics extends Product {
    private int warrantyPeriod;

    // constructor
    public Electronics(String productId, String name, double price, int quantity, int warrantyPeriod) {
        super(productId, name, price, quantity);
        this.warrantyPeriod = warrantyPeriod;
    }

    // copy constructor
    public Electronics(Electronics other) {
        super(other);
        this.warrantyPeriod = other.warrantyPeriod;
    }

    @Override
    public Electronics copy() {
        return new Electronics(this);
    }
}

class Clothing extends Product {
    private String size; // S / M / L

    // constructor
    public Clothing(String productId, String name, double price, int quantity, String size) {
        super(productId, name, price, quantity);
        this.size = size;
    }

    // copy constructor
    public Clothing(Clothing other) {
        super(other);
        this.size = other.size;
    }

    @Override
    public Clothing copy() {
        return new Clothing(this);
    }
}