# Assigment nr. 2

# Part 1
class Product:
    def __init__(self, name: str, price: float, stock: int):
        self._name = name
        self._price = price
        self._stock = stock

    def get_total_price(self, quantity: int) -> float:
        return self._price * quantity
    
    def display_info(self) -> None:
        print(f"Product: {self._name}, Price: ${self._price:.2f}, Stock: {self._stock} units")

class Book(Product):
    def __init__(self, name: str, price: float, stock: int, author: str):
        super().__init__(name, price, stock)
        self._author = author

    def get_total_price(self, quantity: int) -> float:
        total = super().get_total_price(quantity)
        return total * 0.9 if quantity >= 3 else total  # 10% nuolaida perkant 3+
    
    def display_info(self) -> None:
        super().display_info()
        print(f"Author: {self._author}")

class Electronics(Product):
    def __init__(self, name: str, price: float, stock: int, warranty_years: int):
        super().__init__(name, price, stock)
        self._warranty_years = warranty_years

    def get_total_price(self, quantity: int) -> float:
        return super().get_total_price(quantity) + (self._warranty_years * 10)  # +10€ už kiekvienus garantijos metus
    
    def display_info(self) -> None:
        super().display_info()
        print(f"Warranty: {self._warranty_years} years")

# Test nr. 1
'''
products = [
    Book("Python Programming", 30, 10, "John Smith"),
    Electronics("Laptop", 800, 5, 2),
    Book("Data Structures", 25, 8, "Jane Doe")
]

# Polymorphism: same method, different behavior
for product in products:
    print(f"{product._name}: {product.get_total_price(3)} euros")
    product.display_info()
'''

# Part 2
class CartItem:
    def __init__(self, product: str, quantity: int):
        self._product = product
        self._quantity = quantity
    
    def get_subtotal(self) -> float:
        return self._product.get_total_price(self._quantity)

class ShoppingCart:
    def __init__(self):
        self._items = []

    def add_item(self, item: CartItem) -> None:
        self._items.append(item)

    def remove_item(self, product_name: str) -> None:
        self._items = [item for item in self._items if item._product._name != product_name]

    def get_total(self) -> float:
        return sum(item.get_subtotal() for item in self._items)
    
    def display_cart(self) -> None:
        if not self._items:
            print("Shopping Cart is empty.")
            return
        print("Shopping Cart:")
        for item in self._items:
            print(f"{item._product._name} x {item._quantity} = ${item.get_subtotal():.2f}")
        print(f"Total: ${self.get_total():.2f}")
    
class Customer:
    def __init__(self, name: str, email: str, cart: ShoppingCart = None):
        self._name = name
        self._email = email
        self._cart = cart if cart is not None else ShoppingCart()  # Kompozicija - krepšelis sukuriamas viduje

    def shop(self, product: Product, quantity: int) -> None:
        cart_item = CartItem(product, quantity)
        self._cart.add_item(cart_item)

    def view_cart(self) -> None:
        self._cart.display_cart()

    def checkout(self) -> None:
        total = self._cart.get_total()
        print(f"Checking out. Total amount: ${total:.2f}")
        self._cart._items.clear()  

# Test nr. 2
'''
# Create products
book1 = Book("Python Guide", 30, 10, "Smith")
laptop = Electronics("Dell Laptop", 800, 5, 2)
# Create customer (composition: customer owns cart)
customer = Customer("Anna", "anna@email.com")
# Shopping (aggregation: cart references products, doesn't own them)
customer.shop(book1, 2)
customer.shop(laptop, 1)
customer.view_cart()
total = customer.checkout()
# Products still exist after checkout (aggregation)
print(book1._name) # Produktas vis dar egzistuoja po checkout - tai agregacija
# CartItem'ai ištrinti - tai kompozicija
customer.view_cart() # Empty cart
'''

# Part 3

class Order:
    def __init__(self, cart_items):
        self._items = cart_items
        self._shipping_cost = 0

    def get_total(self):
        subtotal = sum(item.get_subtotal() for item in self._items)
        return subtotal + self._shipping_cost

    def display_order(self):
        print(f"Order total: {self.get_total()} euros")

class StandardOrder(Order):
    def __init__(self, cart_items):
        super().__init__(cart_items)
        self._shipping_cost = 5
        self._delivery_days = 5

class ExpressOrder(Order):
    def __init__(self, cart_items):
        super().__init__(cart_items)
        self._shipping_cost = 15
        self._delivery_days = 1

class PickupOrder(Order):
    def __init__(self, cart_items):
        super().__init__(cart_items)
        self._shipping_cost = 0
        self._delivery_days = 0
        self._pickup_location = "Main Store"

# Factory - pagal perduotą tekstą sukuria tinkamą užsakymo objektą
class OrderFactory:
    @staticmethod
    def create_order(order_type, cart_items):
        if order_type == "standard":
            return StandardOrder(cart_items)
        elif order_type == "express":
            return ExpressOrder(cart_items)
        elif order_type == "pickup":
            return PickupOrder(cart_items)
        else:
            raise ValueError(f"Unknown order type: {order_type}")
        
# Test nr. 3        
'''      
book1 = Book("Python Guide", 30, 10, "Smith")
laptop = Electronics("Dell Laptop", 800, 5, 2)        
cart_items = [CartItem(book1, 2), CartItem(laptop, 1)]

# Factory creates appropriate order type
order1 = OrderFactory.create_order("standard", cart_items)
order2 = OrderFactory.create_order("express", cart_items)
order3 = OrderFactory.create_order("pickup", cart_items)

for order in [order1, order2, order3]:
    order.display_order() # Different shipping costs
'''  

# Singleton pattern

class CartManager:
    _instance = None
    def __new__(cls):
        if cls._instance is None:
            cls._instance = super().__new__(cls)
            cls._instance._carts = {} # Dictionary of customer_id: cart
        return cls._instance

    def get_cart(self, customer_id):
        if customer_id not in self._carts:
            self._carts[customer_id] = ShoppingCart()
        return self._carts[customer_id]

    def get_all_carts_total(self):
        return sum(cart.get_total() for cart in
                   self._carts.values())
    
# Test nr. 4

'''
# These are the SAME object
manager1 = CartManager()
manager2 = CartManager()
print(manager1 is manager2) # True
# Both see the same carts
cart1 = manager1.get_cart("customer1")
cart2 = manager2.get_cart("customer1")
print(cart1 is cart2) # True
'''
