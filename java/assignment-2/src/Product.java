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

    public void decQuantity() {
        quantity--;
    }

    public void incQuantity() {
        quantity++;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    @Override
    public String toString() {
        return productId + " " + name + " " + price + " " + quantity;
    }
}

class Electronics extends Product {
    private int warrantyPeriod;

    public Electronics(String productId, String name, double price, int quantity, int warrantyPeriod) {
        super(productId, name, price, quantity);
        this.warrantyPeriod = warrantyPeriod;
    }

    public Electronics(Electronics other) {
        super(other);
        this.warrantyPeriod = other.warrantyPeriod;
    }

    @Override
    public Electronics copy() {
        return new Electronics(this);
    }

    @Override
    public String toString() {
        return super.toString() + " (" + warrantyPeriod + " months warranty)";
    }
}

class Clothing extends Product {
    private String size; // S / M / L

    public Clothing(String productId, String name, double price, int quantity, String size) {
        super(productId, name, price, quantity);
        this.size = size;
    }

    public Clothing(Clothing other) {
        super(other);
        this.size = other.size;
    }

    @Override
    public Clothing copy() {
        return new Clothing(this);
    }

    @Override
    public String toString() {
        return super.toString() + " (Size: " + size + ")";
    }
}