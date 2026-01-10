-- Show how many orders each user has placed.
SELECT user_id, COUNT(*) AS order_count  FROM orders GROUP BY user_id;