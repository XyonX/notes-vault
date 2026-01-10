SELECT name,
CASE
WHEN price<1000 THEN "Budget"
WHEN price >=1000 AND  price<10000 THEN  "MidRange"
ELSE "Premium"
END AS price_category
FROM products