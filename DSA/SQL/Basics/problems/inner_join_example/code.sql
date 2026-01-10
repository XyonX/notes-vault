-- Show the first name, last name, and product name for every order placed.
SELECT u.first_name,
	u.last_name,
	p.name
FROM users u
	INNER JOIN orders o ON o.user_id = u.id
	INNER JOIN order_items oi ON oi.order_id = o.id
	INNER JOIN products p ON  oi.product_id = p.id;