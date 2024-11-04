import java.util.ArrayList;

class ShoppingCart {
    private ArrayList<Item> items;

    public ShoppingCart() {
        items = new ArrayList<>();
    }

    public ArrayList<Item> getItems() {
        return items;
    }

    public void addItem(Item item) {
        items.add(item);
    }

    public void removeItem(String itemId) {
        for (int i = 0; i < items.size(); i++) {
            if (items.get(i).getItemId() == itemId) {
                items.remove(i);
                return;
            }
        }
    }

    public void viewCart() {
        for (int i = 0; i < items.size(); i++) {
            System.out.println(items.get(i));
        }
    }

    public double calculateTotal() {
        int total = 0;
        for (int i = 0; i < items.size(); i++) {
            Item item = items.get(i);
            total += item.getPrice() * item.getQuantity();
        }
        return total;
    }

}
