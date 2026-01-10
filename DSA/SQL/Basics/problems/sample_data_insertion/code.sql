-- Users
INSERT INTO users (id, email, first_name, last_name)
VALUES (1, 'alice@example.com', 'Alice', 'Johnson'),
	(2, 'bob@example.com', 'Bob', 'Smith'),
	(3, 'carol@example.com', 'Carol', 'Taylor');
-- Products
INSERT INTO products (id, name, price, sales_count)
VALUES (1, 'T-Shirt', 499.00, 10),
	(2, 'Phone Case', 299.00, 5),
	(3, 'Laptop', 55000.00, 2),
	(4, 'Mouse', 899.00, 8);
-- Product Images
INSERT INTO product_images (id, product_id, url, is_main)
VALUES (1, 1, 'tshirt_main.jpg', TRUE),
	(2, 1, 'tshirt_side.jpg', FALSE),
	(3, 2, 'phonecase_main.jpg', TRUE),
	(4, 3, 'laptop_main.jpg', TRUE);
-- Orders
INSERT INTO orders (id, user_id, total, created_at)
VALUES (1, 1, 1000.00, '2024-06-01'),
	(2, 2, 56000.00, '2024-06-02'),
	(3, 1, 499.00, '2024-06-10'),
	(4, 3, 899.00, '2024-06-15');
-- Order Items
INSERT INTO order_items (id, order_id, product_id, quantity, price)
VALUES (1, 1, 1, 2, 499.00),
	-- Alice ordered 2 T-Shirts
	(2, 2, 3, 1, 55000.00),
	-- Bob ordered 1 Laptop
	(3, 3, 1, 1, 499.00),
	-- Alice ordered 1 more T-Shirt
	(4, 4, 4, 1, 899.00);
-- Carol ordered 1 Mouse